#ifndef IO_H
    /*
     * Structure for player inputs
     *
     * We have to flag this struct as packed, because GCC is going to try to pad it.
     * This causes issues with the HID protocol we've declared.  It's possible to add in 
     * padding to the HID descriptor, but that's just lazy, and our packets will be twice
     * the size.
     */
    typedef struct __attribute__((packed)) {
        unsigned int PAD_UP : 1;
        unsigned int PAD_DOWN : 1;
        unsigned int PAD_LEFT : 1;
        unsigned int PAD_RIGHT : 1;
        unsigned int CAB_UP : 1;
        unsigned int CAB_DOWN : 1;
        unsigned int CAB_LEFT : 1;
        unsigned int CAB_RIGHT : 1;
    } INPUTS;
#define IO_H
#endif