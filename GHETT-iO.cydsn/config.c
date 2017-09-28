#include "config.h"

config ghettio_config;

void config_initialize (void) {
    config eeprom_config;
    
    // Zero out the GHETT-IO Configuration and the EEPROM config
    memset ((uint8_t*)&ghettio_config, 0, sizeof(config));
    memset ((uint8_t*)&eeprom_config, 0, sizeof (config));
    
    // Start up the EEPROM
    EEPROM_Start();
    CyDelay(EEPROM_WAIT_TIME);
    
    // Attempt to read the config from the EEPROM
    uint8_t *cfg_eeprom = (uint8_t*) (CYDEV_EE_BASE + CONFIG_OFFSET);
    memcpy (&eeprom_config, cfg_eeprom,  sizeof(config));
    
    // Check to see if the configuration has been initialized in EEPROM
    // By looking to see if the magic value has been set properly
    if (eeprom_config.magic != CONFIG_MAGIC) {
        // Set the defaults
        config_set_defaults(&eeprom_config);
        config_write(&eeprom_config);
    }
    
    // Debugger Target
    memcpy (&ghettio_config, &eeprom_config, sizeof(config));
}

void config_set_defaults (config *configuration) {    
    // Zero out the configuration
    memset (configuration, 0, sizeof(config));
    
    // Set the default configuration
    configuration->magic   = CONFIG_MAGIC;
    configuration->mode    = CONFIG_MODE_GHETTIO;
    configuration->version = CONFIG_VERSION;
    
    return;
}

void config_write (config *configuration) {
    // Write a configuration to the EEPROM
    for (uint8_t row = 0; row < sizeof(config) / 16; row++) {
        EEPROM_Write((uint8_t*)(configuration + row), (CONFIG_OFFSET / 16) + row);
    }
}