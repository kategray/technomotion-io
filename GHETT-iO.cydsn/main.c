/**
 * GHETT-iO
 *
 * Handles a single DDR pad, using only a PSoC 5LP dev board
 */
#include <project.h>
#include <stdio.h>

// Input data structures
#include "io.h"

// If multiple descriptors were defined, we could use them
#define USBFS_DESCRIPTOR 0u

// Endpoints 
#define IN_ENDPOINT   1u    // Inputs

// ISR Definition
CY_ISR_PROTO(bootloaderISR);

// These variables hold the input for the players
INPUTS input;

uint8 bootload = 0;

int main()
{
    // ISR Checks if we're supposed to go into the bootloader
    timer_clock_Start();
    Timer_BL_Start();
    isr_BL_ClearPending();
    isr_BL_StartEx(bootloaderISR);
    
    // Enable interrupts (macro for an inline ASM instruction)
    CyGlobalIntEnable;
    
    /*
    uint8 feature_buffer[5] = {0x12, 0x34, 0x56, 0x78, 0x00};
    memcpy(
        USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_FEATURE_BUF,
        feature_buffer, 
        sizeof(feature_buffer)
    );
    */
    
    // Zero out the player array.  The reset interrupt (in CM3Start.c) calls the Start_C function
    // which loops through all the defined sections, initializing memory from flash for predefined
    // memory (constants, pre-initialized variables).  Afterwards, it initializes the remainder of
    // the sections with zeros.  I don't care - I'm going to zero memory anyway, because it's a good
    // habit to get into.  Initialize your variables, people!
    memset(&input, 0u, sizeof(INPUTS));
    
    // Start up USB and wait for enumeration.
    USBFS_Start(USBFS_DESCRIPTOR, USBFS_5V_OPERATION);
    while (0u == USBFS_GetConfiguration())
    {  
        // Wait for USB to enumerate.  It can take a little while.
    }
    
    // Begin USB traffic
    USBFS_LoadInEP(IN_ENDPOINT, (uint8*)&input, sizeof(INPUTS));    
    
    // Loop until power is lost
    for (;;) {
        // Check for acknowledgements from the PC
        if (USBFS_bGetEPAckState(IN_ENDPOINT) != 0) {
            // Input acknowledged, so copy the low and high bits into the player data structure
            // Inputs are active low, so we have to invert them.
            
            uint8 input_data[] = {SR_ARROWS_Read()};
            memcpy (&input, &input_data, sizeof(INPUTS));

            USBFS_LoadInEP(IN_ENDPOINT, (uint8*)&input, sizeof(INPUTS));
        }
        
        // This flag is set by the ISR
        if (bootload) {
            Bootloadable_Load();
        }
    }
}

CY_ISR(bootloaderISR)
{   
    bootload = 1;
}