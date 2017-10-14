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
#ifndef CONFIG_H
#include <project.h>
#include "io.h"

// The data from the USB feature is stored in a variable with a hard to read name
// Alias it to make it simple.
#define FEATURE_BUFFER USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_FEATURE_BUF
#define FEATURE_BUFFER_LEN USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_FEATURE_BUF_SIZE

// When we see this feature report, load the bootloader
#define BOOTLOADER_TRIGGER {0xDE, 0xAD, 0xBE, 0xEF, 0u}

// Request types
#define REQ_CONTROL_READ (0xA2u)
#define REQ_CONTROL_WRITE (0xB2u)
    
// The configuration initialized value should be set to this value to indicate
// that it has been configured.
#define CONFIG_MAGIC (0xAAu) /* 0b10101010 */

// Status flags for features
#define FEATURE_DISABLED (0x00u)
#define FEATURE_ENABLED (0x01u)
    
// Mask for reserved features (used to ensure they aren't set)
#define RESERVED_MASK (0b11100000)

// Mask for supported lights
#define LIGHTS_MASK (0b11110000)
    
// Where in EEPROM the config is stored
#define CONFIG_EEPROM_OFFSET  0u
#define CONFIG_EEPROM_ADDRESS (CYDEV_EE_BASE + CONFIG_EEPROM_OFFSET)

// Configuration is a 16 bit structure
typedef struct __attribute__((packed)) {
    uint8 initialized : 8;
    uint8 mode_itgio : 1;
    uint8 has_selstart : 1;
    uint8 pad_2 : 1;
    uint8 reserved_1 : 1;   // Reserved for future use
    uint8 reserved_2 : 1;   // Reserved for future use
    uint8 reserved_3 : 1;   // Reserved for future use
    uint8 reserved_4 : 1;   // Reserved for future use
    uint8 reserved_5 : 1;   // Reserved for future use
} config;

// Function definitions
extern void config_init();
extern void config_write();

// Bootloader check ISR
#ifdef Bootloadable_GET_RUN_TYPE
CY_ISR_PROTO(Check_BL);
#endif

// Configuration ISR
CY_ISR_PROTO(Check_Config);
    
#define CONFIG_H    
#endif /* CONFIG_H */