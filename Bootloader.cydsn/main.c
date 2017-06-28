/*******************************************************************************
* File Name: main.c
*
* Version: 3.0
*
* Description:
*  This example project demonstrates the basic operation of the Bootloader and 
*  Bootloadable components when the communication interface is a USB.
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

#include <main.h>


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main function performs the following actions:
*   1. Indicates that the bootloader project is running by turning on the LED.
*   2. Starts the bootloader component and it waits for the application update. 
*      After 10 seconds, the code jumps to the application if it is available. 
*      Otherwise waits forever for application upload.
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
    /* Indicates that the bootloader is running. */
#if (CY_PSOC4)
    RGB_LED_ON_RED;
#else
    TURN_ON_LED4;
#endif /* (CY_PSOC4) */

    /* Enters the bootloader to wait for the application update. */
    Bootloader_Start();

    /* Bootloader_Start() never returns. */
    for (;;)
    {
    }
}


/* [] END OF FILE */
