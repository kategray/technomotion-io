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
 *
 * Copyright 2017, Kate Gray
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
 */
#include <project.h>
#include <stdio.h>
#include "main.h"

// Input data structures
#include "io.h"

// At the moment, we have only one USB descriptor.
// Future versions (multi-pad) will need to support additional descriptors.
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
INPUTS input;

int main()
{
    // DMA channel identifier.  DMA channels are used to instruct the Peripheral Hub (PHUB) to transfer data.
    // Chanels hold one or more Transaction Descriptors, which must all have the same source and destination.
    uint8 DMA_INPUTS_Chan;
    
    // Transaction Descriptor.
    // Stores configuration for a DMA transfer.  Can be chained within a DMA channel.
    uint8 DMA_INPUTS_TD[1];
    
    // Allocate the DMA chanel, with bursts of 1 byte, and store the channel number
    DMA_INPUTS_Chan = DMA_Inputs_DmaInitialize(DMA_INPUTS_BYTES_PER_BURST, DMA_INPUTS_REQUEST_PER_BURST, 
    HI16(DMA_INPUTS_SRC_BASE), HI16(DMA_INPUTS_DST_BASE));
    
    // Allocate the transaction descriptor and configure it to copy from the peripheral (status register)
    // to SRAM.  We're only doing a single transfer at a time, and we aren't chaining, so go ahead and
    // disable the TD after completion, rather than calling the next TD.  Set the address to the global
    // input address.
    DMA_INPUTS_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_INPUTS_TD[0], DMA_INPUTS_TD_TRANSFER_INDEFINITELY, 
        DMA_INPUTS_TD[0], DMA_Inputs__TD_TERMOUT_EN);
    CyDmaTdSetAddress(DMA_INPUTS_TD[0], LO16((uint32)SR_Inputs_Status_PTR), LO16((uint32)&input));
    
    // Configure our TD to be the first TD in the "chain" and enable it.
    CyDmaChSetInitialTd(DMA_INPUTS_Chan, DMA_INPUTS_TD[0]);
    CyDmaChEnable(DMA_INPUTS_Chan, 1);
    
    // Periodically update the lights.  A special sequence will enter the bootloader.
    isr_Lights_ClearPending();
    isr_Lights_StartEx(Check_Lights);
        
    // Configure the Status Register interrupts
    SR_Inputs_InterruptEnable();
    
    // Enable interrupts (macro for an inline ASM instruction)
    CyGlobalIntEnable;
    
    // Enable the watchdog timer to reset if this freezes
    CyWdtStart (CYWDT_1024_TICKS, CYWDT_LPMODE_DISABLED);
    
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
    
    // Prime the pump, starting a DMA transfer.  The buffer will be replenished by the endpoint exit callback
    USBFS_LoadInEP(IN_ENDPOINT, USBFS_NULL, sizeof(INPUTS));
    
    // Loop indefinitely
    for(;;) {
    }
}

CY_ISR(Check_Lights) {
    static uint8 trigger[FEATURE_BUFFER_LEN] = BOOTLOADER_TRIGGER;
    
#ifdef Bootloadable_GET_RUN_TYPE
    // Should we invoke the bootloader?
    if (!memcmp(FEATURE_BUFFER, trigger, FEATURE_BUFFER_LEN)) {
        // Clear the ISR
        isr_Lights_ClearPending();
        isr_Lights_Disable();
        
        // Run the bootloader
        Bootloadable_Load();
    }
#endif
}

/*
 * Callback for when USB endpoint one is processed
 */
void USBFS_EP_1_ISR_ExitCallback() {
    // Is our USB buffer empty?
    if (USBFS_GetEPState(IN_ENDPOINT) == USBFS_IN_BUFFER_EMPTY) {
        // Re-arm the DMA to re-fill the buffer
        USBFS_LoadInEP(IN_ENDPOINT, USBFS_NULL, sizeof(INPUTS));
        
        // Reset the watchdog timer
        CyWdtClear();
    }    
}