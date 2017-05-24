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
        unsigned int P1_PAD_UP : 1;
        unsigned int P1_PAD_DOWN : 1;
        unsigned int P1_PAD_LEFT : 1;
        unsigned int P1_PAD_RIGHT : 1;
        unsigned int P1_PAD_UP_LEFT : 1;
        unsigned int P1_PAD_UP_RIGHT : 1;
        unsigned int P1_PAD_LR_LEFT : 1;
        unsigned int P1_PAD_LR_RIGHT : 1;
        unsigned int P1_CAB_UP : 1;
        unsigned int P1_CAB_DOWN : 1;
        unsigned int P1_CAB_LEFT : 1;
        unsigned int P1_CAB_RIGHT : 1;
        unsigned int P1_PAD_CENTER : 1;
        unsigned int P1_CAB_START : 1;
        unsigned int P1_COIN : 1;
        unsigned int SERVICE : 1;
        
        unsigned int P2_PAD_UP : 1;
        unsigned int P2_PAD_DOWN : 1;
        unsigned int P2_PAD_LEFT : 1;
        unsigned int P2_PAD_RIGHT : 1;
        unsigned int P2_PAD_UP_LEFT : 1;
        unsigned int P2_PAD_UP_RIGHT : 1;
        unsigned int P2_PAD_LR_LEFT : 1;
        unsigned int P2_PAD_LR_RIGHT : 1;
        unsigned int P2_CAB_UP : 1;
        unsigned int P2_CAB_DOWN : 1;
        unsigned int P2_CAB_LEFT : 1;
        unsigned int P2_CAB_RIGHT : 1;
        unsigned int P2_PAD_CENTER : 1;
        unsigned int P2_CAB_START : 1;
        unsigned int P2_COIN : 1;
        unsigned int P2_CREDIT : 1;
    } INPUTS;
    
    /*
     * Lights are implemented globally, rather than per-player.  This is due to the way
     * that StepMania implements things internally, as well due to cabinet lights not
     * necessarily belonging to any particular player.
     *
     * For this first version, we've chosen to represent the lights as 16 bits, compatible
     * with the ITG-IO.  This will be expanded in the future, but in order to remain compatible,
     * it will likely be necessary to make available multiple firmware variants.
     */
    typedef struct __attribute__((packed)) {
        unsigned int MARQUEE_UP_LEFT : 1;
        unsigned int MARQUEE_UP_RIGHT : 1;
        unsigned int MARQUEE_LR_LEFT : 1;
        unsigned int MARQUEE_LR_RIGHT : 1;
        unsigned int P1_PANEL : 1;
        unsigned int P2_PANEL : 1;
        unsigned int P1_UP : 1;
        unsigned int P1_DOWN : 1;
        unsigned int P1_LEFT : 1;
        unsigned int P1_RIGHT : 1;
        unsigned int P2_UP : 1;
        unsigned int P2_DOWN : 1;
        unsigned int P2_LEFT : 1;
        unsigned int P2_RIGHT : 1;
        unsigned int CAB_BASS : 1;
        unsigned int SELFDESTRUCT : 1; 
    } LIGHTS;
#define IO_H
#endif