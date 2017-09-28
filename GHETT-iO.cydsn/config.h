#ifndef CONFIG_H
/*
 * Copyright 2017, Kate Gray
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
 */
    
#include <project.h>
    
// Uninitialized EEPROM has a value of 0xFF, so this will never happen accidentally
#define CONFIG_MAGIC            0x31337088u
    
// Constants
#define CONFIG_UNINITIALIZED    1u
#define CONFIG_INITIALIZED      2u
    
#define CONFIG_MODE_GHETTIO     0u
#define CONFIG_MODE_ITGIO       1u

// Offset in memory where the configuration is stored
#define CONFIG_OFFSET           0u
    
// Configuration version
#define CONFIG_VERSION          1u
    
// Per the datasheet, there needs to be a delay of at least 5 microseconds.
// Two milliseconds should be far more than enough
#define EEPROM_WAIT_TIME        2u
    
// Defines configuration (stored in EEPROM)
typedef struct __attribute__((packed)) {
    uint32  magic;              // Bytes 0-3
    uint16  version;            // Bytes 4-5
    uint8   mode;               // Byte 6
    uint8   reserved[9];        // Bytes 7-15
    uint8   serial[24];         // Bytes 16-39
    uint8   secret[40];         // Bytes 40-79
} config;

// External references
extern config ghettio_config;
void config_initialize (void);
void config_set_defaults (config *configuration);
void config_write (config *configuration);
    
#define CONFIG_H
#endif