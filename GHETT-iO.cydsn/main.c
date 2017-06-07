/**
 * Stupid IO Device
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

// These variables hold the input for the players
INPUTS input;

int main()
{
    // Enable interrupts (macro for an inline ASM instruction)
    CyGlobalIntEnable;
    
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
            uint8 input_data[] = {(~SR_ARROWS_Read()) & 0b00001111};
            memcpy (&input, &input_data, sizeof(INPUTS));

            USBFS_LoadInEP(IN_ENDPOINT, (uint8*)&input, sizeof(INPUTS));
        }
    }
}