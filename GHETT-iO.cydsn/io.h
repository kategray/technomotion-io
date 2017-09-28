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
    
// Single pad (GHETT-iO mode)
typedef struct __attribute__((packed)) {
    uint8 PAD_UP : 1;
    uint8 PAD_DOWN : 1;
    uint8 PAD_LEFT : 1;
    uint8 PAD_RIGHT : 1;
    uint8 START : 1;
    uint8 SELECT : 1;
    uint8 COIN : 1;
    uint8 SERVICE : 1;
} input_single;

// Dual pad (Ghett-IO mode)
typedef struct __attribute__((packed)) {
    uint8 P1_UP : 1;
    uint8 P1_DOWN : 1;
    uint8 P1_LEFT : 1;
    uint8 P1_RIGHT : 1;
    uint8 START : 1;
    uint8 SELECT : 1;
    uint8 COIN : 1;
    uint8 SERVICE : 1;
} input_double;

// Full inputs (Tech-IO mode)
typedef struct __attribute__((packed)) {
    // Bits 0-7
    uint8 P1_UP : 1;
    uint8 P1_DOWN : 1;
    uint8 P1_LEFT : 1;
    uint8 P1_RIGHT : 1;
    uint8 P1_UP_LEFT : 1;
    uint8 P1_UP_RIGHT : 1;
    uint8 P1_DOWN_LEFT : 1;
    uint8 P1_DOWN_RIGHT : 1;

    // Bits 8-15
    uint8 P1_CAB_UP : 1;
    uint8 P1_CAB_DOWN : 1;
    uint8 P1_CAB_LEFT : 1;
    uint8 P1_CAB_RIGHT : 1;
    uint8 P1_CENTER : 1;
    uint8 P1_START : 1;
    uint8 P1_COIN : 1;
    uint8 SERVICE : 1;
    
    // Bits 16-23
    uint8 P2_UP : 1;
    uint8 P2_DOWN : 1;
    uint8 P2_LEFT : 1;
    uint8 P2_RIGHT : 1;
    uint8 P2_UP_LEFT : 1;
    uint8 P2_UP_RIGHT : 1;
    uint8 P2_DOWN_LEFT : 1;
    uint8 P2_DOWN_RIGHT : 1;
    
    // Bits 24-31
    uint8 P2_CAB_UP : 1;
    uint8 P2_CAB_DOWN : 1;
    uint8 P2_CAB_LEFT : 1;
    uint8 P2_CAB_RIGHT : 1;
    uint8 P2_CENTER : 1;
    uint8 P2_START : 1;
    uint8 P2_COIN : 1;
    uint8 COURTESY : 1;
} input_techio;

// ITG-IO Compatibility
// See docs/ITG-IO Manual.pdf
typedef struct __attribute__((packed)) {
    // Byte 0
    uint8 P1_UP : 1;            // 0.0
    uint8 P1_DOWN : 1;          // 0.1
    uint8 P1_LEFT : 1;          // 0.2
    uint8 P1_RIGHT : 1;         // 0.3
    uint8 P1_START : 1;         // 0.4
    uint8 P1_CAB_LEFT : 1;      // 0.5
    uint8 P1_CAB_RIGHT : 1;     // 0.6
    uint8 P2_UP : 1;            // 0.7
    
    // Byte 1
    uint8 P2_DOWN : 1;          // 1.0
    uint8 P2_LEFT : 1;          // 1.1
    uint8 P2_RIGHT : 1;         // 1.2
    uint8 P2_START : 1;         // 1.3
    uint8 P2_CAB_LEFT : 1;      // 1.4
    uint8 P2_CAB_RIGHT : 1;     // 1.5
    uint8 SERVICE : 1;          // 1.6
    uint8 COIN : 1;             // 1.7
} input_itgio;

#define IO_H
#endif