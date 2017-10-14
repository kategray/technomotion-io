/**
 * GHETT-iO
 *
 * Handles configuration of the GHETT-iO
 *
 * Contains functions to manage the configuration by reading from and writing
 * to the EEPROM, as well as to handle vendor-specific requests
 *
 * Copyright 2017, Kate Gray
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
 */
#include <project.h>
#include <stdio.h>
#include "config.h"
#include "io.h"

// Holds the configuration for the device
config controlBuffer;
config currentConfig;

/*
 * Retrieve the current configuration from the EEPROM and apply it
 */
void config_init()
{
    // Initialize the EEPROM component
    EEPROM_Start();
    
    // Read the memory from the EEPROM
    memcpy(&currentConfig, (const void *)(CONFIG_EEPROM_ADDRESS), sizeof(config));    
    memcpy(&controlBuffer, &currentConfig, sizeof(config));
}

/*
 * Write the current configuration to the EEPROM
 */
void config_write()
{   
    // The stored temperature must be accurate in order to ensure reliable performance
    EEPROM_UpdateTemperature();
    
    // Write out both bytes of the control buffer
    EEPROM_WriteByte(*(uint8*)(&controlBuffer), CONFIG_EEPROM_OFFSET);
    EEPROM_WriteByte(*(uint8*)(&controlBuffer + 1), CONFIG_EEPROM_OFFSET + 1);
    
    // Copy the buffer to the current config
    memcpy(&currentConfig, &controlBuffer, sizeof(config));    
}

/*
 * Callback for the USB vendor commands.
 *
 * This function is called by USBFS_HandleVendorRqst in USBFS_vnd.c if the
 * request has not already been handled (for example, by the general HID or
 * HID class handlers.
 */
uint8 USBFS_HandleVendorRqst_Callback () {
    // Set to true if we have handled the request
    uint8 requestHandled = USBFS_FALSE;
    
    switch(USBFS_bRequestReg)
    {
        // Control read
        case REQ_CONTROL_READ:
            // Set the transfer size
		    USBFS_currentTD.wCount = sizeof(controlBuffer); 
        
			// Set pointer to data array (defined earlier) for control transfers
			USBFS_currentTD.pData = (uint8*)&controlBuffer; 
            
			// Initialize a control read transaction
			requestHandled = USBFS_InitControlRead(); 
            break;  
        // Control write
        case REQ_CONTROL_WRITE:
            // Set the transfer size
		    USBFS_currentTD.wCount = sizeof(controlBuffer); 
            
            // If the magic value is not set in the control transfer, set the lights instead
            if (CONFIG_MAGIC != USBFS_wValueHiReg)
            {
                // Write the lights status register
                CR_Lights_Write(USBFS_wValueLoReg & LIGHTS_MASK);
                
                // It's possible to handle the control transfer directly when it's short enough (2 Bytes)
                requestHandled = USBFS_InitNoDataControlTransfer(); 
            }
            else
            {                
    			// Set pointer to data array (defined earlier) for control transfers
    			USBFS_currentTD.pData = (uint8*)&controlBuffer; 
                
    			// Initialize a control read transaction
    			requestHandled = USBFS_InitControlRead();
                
            }
            break;
    }
    
    return requestHandled;
}

#ifdef Bootloadable_GET_RUN_TYPE
// ISR to check if the Bootloader should run.  We keep this out of the main() loop for
// performance reasons.
CY_ISR(Check_BL) {
    static uint8 trigger[FEATURE_BUFFER_LEN] = BOOTLOADER_TRIGGER;
    
    // Should we invoke the bootloader?
    if (!memcmp(FEATURE_BUFFER, trigger, FEATURE_BUFFER_LEN)) {
        // Clear the ISR
        isr_BL_ClearPending();
        isr_BL_Disable();
        
        // Run the bootloader
        Bootloadable_Load();
    }
}
#endif

/*
 * Callback for when USB endpoint 0 (config) is processed
 */
void USBFS_EP_0_ISR_ExitCallback() {
    // Has the configuration changed?
    if (0 != memcmp(&controlBuffer, &currentConfig, sizeof(config)))
    {
        config_write();
    }
}