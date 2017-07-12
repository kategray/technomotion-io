#ifndef IO_H
    /*
     * Structure for player inputs
     *
     * We have to flag this struct as packed, because GCC is going to try to pad it.
     * This causes issues with the HID protocol we've declared.  It's possible to compensate by 
     * adding in padding to the HID descriptor, but that's just lazy, and our packets will be twice
     * the size.
     */
    #include <project.h>
    
    // Represents the inputs from the pad
    typedef struct __attribute__((packed)) {
        uint8 pad_up : 1;
        uint8 pad_down : 1;
        uint8 pad_left : 1;
        uint8 pad_right : 1;
        uint8 start : 1;
        uint8 select : 1;
        uint8 coin : 1;
        uint8 service : 1;
    } input;
    
    // Represents the outputs from the pad
    typedef struct __attribute__((packed)) {
        uint8 light_up: 1;
        uint8 light_down: 1;
        uint8 light_left: 1;
        uint8 light_right: 1;
    } output;
#define IO_H
#endif