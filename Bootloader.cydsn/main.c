/*
 * Copyright 2017, Kate Gray
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
 */

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
    TURN_ON_LED1;
#endif /* (CY_PSOC4) */

    /* Enters the bootloader to wait for the application update. */
    Bootloader_Start();

    /* Bootloader_Start() never returns. */
    for (;;)
    {
    }
}


/* [] END OF FILE */
