/*******************************************************************************
* File Name: main.c
*
* Version: 3.0
*
* Description:
*  This code example demonstrates USB HID interface class operation by 
*  implementing a 3-button mouse. When the code is run, the mouse cursor moves 
*  from the right to the left, and vice-versa.
*
*
* Related Document:
*  Device Class Definition for Human Interface Devices (HID)
*  Firmware Specification- Version 1.11
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>

#define USBFS_DEVICE        (0u)

#define LIGHT_ENDPOINT      (1u)
#define LIGHT_DATA_LEN      (2u)

uint8 lightData[LIGHT_DATA_LEN] = {0u, 0u};


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Wraps the OUT data coming from the host back to the host on a subsequent IN.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{
    unsigned int length;
    uint8_t buffer[9];
    
    CyGlobalIntEnable;
    
    /* Start USBFS operation with 5-V operation. */
    USBFS_Start(USBFS_DEVICE, USBFS_5V_OPERATION);
    
    USBFS_EnableOutEP(LIGHT_ENDPOINT);

    /* Wait for device to enumerate */
    while (0u == USBFS_GetConfiguration())
    {
    }

    for(;;)
    {
       /* Check if configuration is changed. */
        if (0u != USBFS_IsConfigurationChanged())
        {
            /* Re-enable endpoint when device is configured. */
            if (0u != USBFS_GetConfiguration())
            {
                /* Enable OUT endpoint to receive data from host. */
                USBFS_EnableOutEP(LIGHT_ENDPOINT);
            }
        }

        /* Check if data was received. */
        if (USBFS_OUT_BUFFER_FULL == USBFS_GetEPState(LIGHT_ENDPOINT))
        {
            length = USBFS_GetEPCount (LIGHT_ENDPOINT);
            if (length > sizeof(buffer)) {
                length = sizeof(buffer);
            }
            
            USBFS_ReadOutEP(LIGHT_ENDPOINT, buffer, length);
            
            // The first byte is part of the USB protocol.  The second byte is a command.
            // We want the third and fourth bytes.
            if (length > 2 && buffer[1] == 0xdd) {
                CR_PORT1_Write(~buffer[2]);
                CR_PORT2_Write(~buffer[3]);
            }            
        }

    }
}

/* [] END OF FILE */
