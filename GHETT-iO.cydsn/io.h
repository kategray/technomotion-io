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
    
    typedef struct __attribute__((packed)) {
        uint8 PAD_UP : 1;
        uint8 PAD_DOWN : 1;
        uint8 PAD_LEFT : 1;
        uint8 PAD_RIGHT : 1;
        uint8 START : 1;
        uint8 SELECT : 1;
        uint8 COIN : 1;
        uint8 SERVICE : 1;
    } INPUTS;
#define IO_H
#endif