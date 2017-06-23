/* This program is free software. It comes without any warranty, to
     * the extent permitted by applicable law. You can redistribute it
     * and/or modify it under the terms of the Do What The Fuck You Want
     * To Public License, Version 2, as published by Sam Hocevar. See
     * http://www.wtfpl.net/ for more details. */
#include "project.h"

#define USBFS_BL 0

int main(void)
{   
    BL_USBFS_Stop();
    if ((BL_GET_RUN_TYPE == BL_START_BTLDR) || BL_WAIT_Read() == 0u) {
        BL_SET_RUN_TYPE(BL_START_BTLDR);
        BL_USBFS_Start(USBFS_BL, BL_USBFS_DWR_POWER_OPERATION);
    }
    
    CyDelay(5000);
    
    // Start the bootloader application, or the bootloader if the pin was held
    BL_Start();
    
    // We will never hit this, but the compiler complains if we don't loop in main
    for (;;) {
    }
}

/* [] END OF FILE */
