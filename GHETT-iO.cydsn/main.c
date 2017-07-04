/**
 * GHETT-iO
 *
 * Handles a single DDR pad, using only a PSoC 5LP dev board. (CY8CKIT-059)
 *
 * The CY8CKIT-059 development board is a cheap I/O board based on the PSoC 5LP
 * line of microcontrollers from Cypress Semiconductor.  These boards combine
 * an ARM cortex M3 CPU with programmable logic and analog capabilities.
 *
 * The CY8CKIT-059 is a cheap ($10) board with the same pitch (0.100in) as the
 * connectors used by the stage PCB in Dance Dance Revolution arcade machines.
 * Due to the failure of many stage PCBS (as well as the lack of updates to
 * the platform after 2002), many users wish to connect their dance stages to
 * modern desktop computers.  The programmable logic fabric present in the PSoC
 * enables very high-speed input processing, as it is possible to debounce and
 * invert the (active low) inputs.  Built-in input protection (diode clamps to
 * VCC and ground on all inputs), as well as built-in buffers and pull-up
 * resistors permit the PSoC to be configured to handle all of the inputs
 * without the need to add any additional hardware to the board except
 * connectors.
 */
#include <project.h>
#include <stdio.h>
#include "main.h"

// Input data structures
#include "io.h"

// If multiple descriptors were defined, we could use them
#define USBFS_DESCRIPTOR 0u

// Endpoints 
#define IN_ENDPOINT   1u    // Inputs

#ifdef Bootloadable_GET_RUN_TYPE
// Bootloader ISR Definition
CY_ISR_PROTO(bootloaderISR);

// Bootloader invocation flag
CYBIT runBootloader = 0;
#endif

// Holds player input
volatile INPUTS input;

int main()
{
    // DMA channel identifier.  DMA channels are used to instruct the Peripheral Hub (PHUB) to transfer data.
    // Chanels hold one or more Transaction Descriptors, which must all have the same source and destination.
    uint8 DMA_INPUTS_Chan;
    
    // Transaction Descriptor.
    // Stores configuration for a DMA transfer.  Can be chained within a DMA channel.
    uint8 DMA_INPUTS_TD[1];
    
    // Allocate the DMA chanel, with bursts of 1 byte, and store the channel number
    DMA_INPUTS_Chan = DMA_INPUTS_DmaInitialize(DMA_INPUTS_BYTES_PER_BURST, DMA_INPUTS_REQUEST_PER_BURST, 
    HI16(DMA_INPUTS_SRC_BASE), HI16(DMA_INPUTS_DST_BASE));
    
    // Allocate the transaction descriptor and configure it to copy from the peripheral (status register)
    // to SRAM.  We're only doing a single transfer at a time, and we aren't chaining, so go ahead and
    // disable the TD after completion, rather than calling the next TD.  Set the address to the global
    // input address.
    DMA_INPUTS_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_INPUTS_TD[0], DMA_INPUTS_TD_TRANSFER_INDEFINITELY, 
        DMA_INPUTS_TD[0], DMA_INPUTS__TD_TERMOUT_EN);
    CyDmaTdSetAddress(DMA_INPUTS_TD[0], LO16((uint32)SR_INPUTS_Status_PTR), LO16((uint32)&input));
    
    // Configure our TD to be the first TD in the "chain" and enable it.
    CyDmaChSetInitialTd(DMA_INPUTS_Chan, DMA_INPUTS_TD[0]);
    CyDmaChEnable(DMA_INPUTS_Chan, 1);
    
    #ifdef Bootloadable_GET_RUN_TYPE
    // Periodically (10 times per second) check to see if we should enter the bootloader.
    isr_BL_ClearPending();
    isr_BL_StartEx(Check_BL);
    #endif
        
    // Configure the Status Register interrupts
    SR_INPUTS_InterruptEnable();
    
    // Enable interrupts (macro for an inline ASM instruction)
    CyGlobalIntEnable;
    
    // Zero out the player array.  This is really not needed, but it's still a good habit.
    // The reset interrupt (in CM3Start.c) calls the Start_C function which loops through all 
    // the defined sections, initializing memory from flash for predefined memory (constants, pre-
    // initialized variables).  Afterwards, it initializes the remainder of the memory with zeros.
    // On top of that, this is going to be initialized from the status register by DMA, and the
    // value is not particularly important.
    memset((uint8*)&input, 0u, sizeof(INPUTS));
    
    // Start up USB and wait for enumeration.
    USBFS_Start(USBFS_DESCRIPTOR, USBFS_5V_OPERATION);
    while (0u == USBFS_GetConfiguration())
    {  
        // Wait for USB to enumerate.  It can take a little while.
    }
    
    // The USBFS component is configured to use DMA with automatic buffer management, and USB is 
    // handled by the Serial Interface Engine (SIE). Timing on USB transfers is critical, so an 
    // arbiter is used to marshall requests from the SIE, the CPU, and the DMA interface, with priority
    // given to the SIE.
    // 
    // Due to the critical nature of the timing, it is not possible to configure the SIE to pull it's 
    // data directly from peripherals using the DMA bus.  Only memory to peripheral transfers (SRAM
    // to USB are supported.  We work around this by using SRAM as an intermediary.
    //
    // Because DMA is enabled, this function will automatically configure the USBFS_EP1 DMA channel (channel
    // 0) for transfers from SRAM to the SIE, starting at &input.  If DMA were disabled, this would instead
    // copy the data to a buffer, and it would be necessary to periodically fill the buffer.
    USBFS_LoadInEP(IN_ENDPOINT, (uint8*)&input, sizeof(INPUTS));
    
    // The default behaviour of the USBFS is intended for situations where there is a finite amount of input
    // (for example, an ADC at a fixed clock).  As such, it configures a TD to terminate as soon as the buffer
    // is exhausted.  Additionally, the USBFS component does not make available a hardware trigger for an ISR
    // to replenish the buffer.  This effectively requires the use of the CPU in order to fill the buffer for
    // USB requests.
    // USBFS_LoadInEP(IN_ENDPOINT, USBFS_NULL, sizeof(INPUTS));
    
    /*
    // Disable the DMA channel
    CyDmaChDisable (USBFS_DmaChan[IN_ENDPOINT]);
    
    // Clear any pending event flags
    USBFS_EP[IN_ENDPOINT].apiEpState = USBFS_NO_EVENT_PENDING;
    
    // Store the length and clear the full flag
    USBFS_inLength[IN_ENDPOINT]  = sizeof(INPUTS);
    USBFS_inBufFull[IN_ENDPOINT] = 0u;
    
    // Configure the TD to loop indefinitely
    CyDmaTdSetConfiguration (USBFS_DmaTd[IN_ENDPOINT], DMA_INPUTS_TD_TRANSFER_INDEFINITELY, 
        USBFS_DmaTd[IN_ENDPOINT], DMA_INPUTS__TD_TERMOUT_EN);
    
    // Set the lower bits of the target address for the TD.
    CyDmaTdSetAddress (
        USBFS_DmaTd[IN_ENDPOINT],       // Set the TD configuration for the primary endpoint
        LO16((uint32) &input),          // Copy from input
        LO16((uint32) &USBFS_ARB_EP_BASE.arbEp[IN_ENDPOINT].rwDr)   // Copy to the USBFS registers to go out
    );
    
    // Clear pending DMA requests
    CyDmaClearPendingDrq (USBFS_DmaChan[IN_ENDPOINT]);
    
    // Set the starting TD, and start it
    CyDmaChSetInitialTd (USBFS_DmaChan[IN_ENDPOINT], USBFS_DmaTd[IN_ENDPOINT]);
    CyDmaChEnable (USBFS_DmaChan[IN_ENDPOINT], 1u);
    
    // Set the DMA data ready flag
    USBFS_ARB_EP_BASE.arbEp[IN_ENDPOINT].epCfg |= USBFS_ARB_EPX_CFG_IN_DATA_RDY;
    
    // Arm the DMA endpoint
    USBFS_SIE_EP_BASE.sieEp[IN_ENDPOINT].epCr0 = USBFS_EP[IN_ENDPOINT].epMode;
    */
    // Loop until power is lost
    for (;;) {
        if (USBFS_GetEPState(1) == USBFS_IN_BUFFER_EMPTY) {
            USBFS_LoadInEP(IN_ENDPOINT, USBFS_NULL, sizeof(INPUTS));
        }
    }
}

#ifdef Bootloadable_GET_RUN_TYPE
// ISR to check if the Bootloader should run.  We keep this out of the main() loop for
// performance reasons.
CY_ISR(Check_BL) {
    static uint8 trigger[FEATURE_BUFFER_LEN] = BOOTLOADER_TRIGGER;
    
    // Should we invoke the bootloader?
    if (!memcmp(FEATURE_BUFFER, trigger, FEATURE_BUFFER_LEN)) {
        // Clear the ISR
        isr_BL_ClearPending();
        isr_BL_Disable();
        
        // Run the bootloader
        Bootloadable_Load();
    }
}
#endif