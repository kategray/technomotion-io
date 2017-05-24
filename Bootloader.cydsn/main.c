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

#define USBFS_BL 0

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    // Read the bootloader pin.  If it's 0 (active low),
    // go ahead and force the bootloader to start
    if(BL_WAIT_Read() == 0){
        BL_SET_RUN_TYPE(BL_START_BTLDR);
        BL_USBFS_Start(USBFS_BL, BL_USBFS_DWR_POWER_OPERATION);
    } else {
        // Ensure that the application is started instead
        BL_SET_RUN_TYPE(BL_START_APP);
        BL_USBFS_Stop();
    }
    
    // Start the bootloader application, or the bootloader if the pin was held
    BL_Start();
    
    // We will never hit this, but the compiler complains if we don't loop in main
    for (;;) {
    }
}

/* [] END OF FILE */
