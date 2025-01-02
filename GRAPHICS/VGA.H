#ifndef VGA_H
#define VGA_H

#include "UTIL/TYPES.H"

byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x, y, c) *(VGA+(x)+(y)*SCREEN_WIDTH)=c
#define GETPIX(x, y) *(VGA+(x)+(y)*SCREEN_WIDTH)

void setMode(byte mode);
void clear(int COLOR);

#endif
