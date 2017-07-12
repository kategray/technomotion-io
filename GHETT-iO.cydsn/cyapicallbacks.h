/*
 * Copyright 2017, Kate Gray
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
 */
#ifndef CYAPICALLBACKS_H
#include <cytypes.h>
    
// Enable the USBFS endpoint 0 (control) callback
#define USBFS_EP_0_ISR_EXIT_CALLBACK
extern void USBFS_EP_0_ISR_ExitCallback();
    
// Enable the USBFS endpoint 1 (input) callback
#define USBFS_EP_1_ISR_EXIT_CALLBACK
extern void USBFS_EP_1_ISR_ExitCallback();

// Callback function for handling vendor requests
#define USBFS_HANDLE_VENDOR_RQST_CALLBACK
extern uint8 USBFS_HandleVendorRqst_Callback();

#define CYAPICALLBACKS_H    
#endif /* CYAPICALLBACKS_H */   
/* [] */
