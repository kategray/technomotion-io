/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    // Start the two PWM engines for the LED pulsing
    PWM_Primary_Start();
    PWM_Secondary_Start();

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
