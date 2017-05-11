/**
 * Emulates an ITG-IO device.
 *
 * The ITG-IO has two endpoints.  The control endpoint (endpoint 0) is used to
 * send outputs to the machine (lights, coin counter, etc.).  Endpoint one is
 * an isochronous endpoint that passes the inputs as bitfields.
 */
#include <project.h>
#include <stdio.h>

// Input data structures
#include "io.h"

// If multiple descriptors were defined, we could use them
#define USBFS_DESCRIPTOR 0u

// Endpoints
#define P1_IN_ENDPOINT  1u
#define P2_IN_ENDPOINT  2u

// These variables hold the input for the players
PLAYER player_1;
PLAYER player_2;
char message[128];

int main()
{
    // Enable interrupts (macro for an inline ASM instruction)
    CyGlobalIntEnable;
    
    // Zero out the player array.  The reset interrupt (in CM3Start.c) calls the Start_C function
    // which loops through all the defined sections, initializing memory from flash for predefined
    // memory (constants, pre-initialized variables).  Afterwards, it initializes the remainder of
    // the sections with zeros.  I don't care - I'm going to zero memory anyway, because it's a good
    // habit to get into.  Initialize your variables, people!
    memset(&player_1, 0u, sizeof(PLAYER));
    memset(&player_2, 0u, sizeof(PLAYER));
    
    // Start up USB and wait for enumeration.
    USBFS_Start(USBFS_DESCRIPTOR, USBFS_5V_OPERATION);
    while (0u == USBFS_GetConfiguration())
    {  
        // Wait for USB to enumerate.  It can take a little while.
    }
    
    // Begin USB traffic
    USBFS_LoadInEP(P1_IN_ENDPOINT, (uint8*)&player_1, sizeof(PLAYER));
    USBFS_LoadInEP(P2_IN_ENDPOINT, (uint8*)&player_2, sizeof(PLAYER));
    

    // Loop until power is lost
    for (;;) {
        // Check for acknowledgements from the PC
        if (USBFS_bGetEPAckState(P1_IN_ENDPOINT) != 0) {
            // Player 1 is acknowledged, so copy the low and high bits into the player data structure
            // Inputs are active low, so we have to invert them.
            uint16 p1_data = ~(((uint16)SR_P1_HIGH_Read() << 8) + (uint16)SR_P1_LOW_Read());
            memcpy (&player_1, &p1_data, sizeof(PLAYER));
            
            player_1.COIN = 1;

            USBFS_LoadInEP(P1_IN_ENDPOINT, (uint8*)&player_1, sizeof(PLAYER));
        }
        
        if (USBFS_bGetEPAckState(P2_IN_ENDPOINT) != 0) {
            // Copy player 2 into the data structure
            uint16 p2_data = ~(((uint16)SR_P2_HIGH_Read() << 8) + (uint16)SR_P2_LOW_Read());
            memcpy (&player_2, &p2_data, sizeof(PLAYER));
            
            USBFS_LoadInEP(P2_IN_ENDPOINT, (uint8*)&player_2, sizeof(PLAYER));
        }
    }
}