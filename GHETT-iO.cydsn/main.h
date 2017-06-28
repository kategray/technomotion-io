#ifndef MAIN_H
#include <project.h>

// Bootloader check ISR
CY_ISR_PROTO(CHECK_BL);
    
// The data from the USB feature is stored in a variable with a hard to read name
// Alias it to make it simple.
#define FEATURE_BUFFER USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_FEATURE_BUF
#define FEATURE_BUFFER_LEN USBFS_DEVICE0_CONFIGURATION0_INTERFACE0_ALTERNATE0_HID_FEATURE_BUF_SIZE

// When we see this feature report, load the bootloader
#define BOOTLOADER_TRIGGER {0xDE, 0xAD, 0xBE, 0xEF, 0u}
    
#endif /* MAIN_H */