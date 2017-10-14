/*
 * Copyright 2017, Kate Gray
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
 */
#ifndef MAIN_H
#include <project.h>

#ifdef Bootloadable_GET_RUN_TYPE
// Bootloader check ISR
CY_ISR_PROTO(Check_BL);
#endif
    
// The data from the USB feature is stored in a variable with a hard to read name
// Alias it to make it simple.
#define FEATURE_BUFFER USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_FEATURE_BUF
#define FEATURE_BUFFER_LEN USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_FEATURE_BUF_SIZE

// When we see this feature report, load the bootloader
#define BOOTLOADER_TRIGGER {0xDE, 0xAD, 0xBE, 0xEF, 0u}

// Defines for DMA_INPUTS.  Sets up a 1 byte burst from the Peripheral to SRAM
#define DMA_INPUTS_BYTES_PER_BURST 1                // DMA transfers should burst according to the TD
#define DMA_INPUTS_REQUEST_PER_BURST 1              // Automatically perform more bursts as needed
#define DMA_INPUTS_SRC_BASE (CYDEV_PERIPH_BASE)     // Base address for the source
#define DMA_INPUTS_DST_BASE (CYDEV_SRAM_BASE)       // Base address for the destination
#define DMA_INPUTS_TD_TRANSFER_INDEFINITELY 0       // Continue DMA indefinitely
    
#endif /* MAIN_H */