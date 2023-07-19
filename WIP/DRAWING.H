#ifndef DRAWING_H
#define DRAWING_H

#include <dos.h>
#include <math.h>

typedef unsigned char byte;

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03
#define SCREEN_HEIGHT 200
#define SCREEN_WIDTH 320

#define WHITE 31

byte far *VGA = (byte far *)0xA0000000L;

#define SETPIX(x, y, c) *(VGA+(x)+(y)*SCREEN_WIDTH)=c
#define GETPIX(x, y) *(VGA+(x)+(y)*SCREEN_WIDTH)

void swap(int *a, int *b){
 int temp = *a;
 *a = *b;
 *b = temp;
}

void setMode(byte mode){
 union REGS regs;
 regs.h.ah = SET_MODE;
 regs.h.al = mode;
 int86(VIDEO_INT, &regs, &regs);
}

void line(int x0, int y0, int x1, int y1, int color){
 int dx;
 int dy;
 int sx;
 int sy;
 int err;
 int e2;

 dx = abs(x1 - x0);
 dy = abs(y1 - y0);
 sx = (x0 < x1) ? 1 : -1;
 sy = (y0 < y1) ? 1 : -1;
 err = dx - dy;

 while(1){
  SETPIX(x0, y0, color);

  if(x0 == x1 && y0 == y1)
   break;

  e2 = 2 * err;

  if(e2 > -dy){
   err -= dy;
   x0 += sx;
  }

  if(e2 < dx){
   err += dx;
   y0 += sy;
  }

 }

}

void triangle(int x0, int y0, int x1, int y1, int x2, int y2, int color){

 int totalHeight;
 int segmentHeight;

 float alpha;
 float beta;

 int ax;
 int bx;

 int x;
 int y;

 if(y0 > y1){
  swap(&x0, &x1);
  swap(&y0, &y1);
 }

 if(y0 > y2){
  swap(&x0, &x2);
  swap(&y0, &y2);
 }

 if(y1 > y2){
  swap(&x1, &x2);
  swap(&y1, &y2);
 }

 if(y0 == y2)
  return;

 totalHeight = y2 - y0;

 for(y = y0; y < y1; y++){
  segmentHeight = y1 - y0 + 1;
  alpha = (float)(y - y0) / totalHeight;
  beta = (float)(y - y0) / segmentHeight;
  ax = x0 + (x2 - x0) * alpha;
  bx = x0 + (x1 - x0) * beta;

  if(ax > bx)
   swap(&ax, &bx);

  for(x = ax; x <= bx; x++){
   SETPIX(x, y, color);
  }

 }

 for(y = y1; y <= y2; y++){
  segmentHeight = y2 - y1 + 1;
  alpha = (float)(y - y0) / totalHeight;
  beta = (float)(y - y1) / segmentHeight;
  ax = x0 + (x2 - x0) * alpha;
  bx = x1 + (x2 - x1) * beta;

  if(ax > bx)
   swap(&ax, &bx);

  for(x = ax; x <= bx; x++){
   SETPIX(x, y, color);
  }

 }

}

void wireTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color){
 line(x0, y0, x1, y1, color);
 line(x1, y1, x2, y2, color);
 line(x2, y2, x0, y0, color);
}


void drawBackground(){
 int x, y;

 for(y = 0; y < SCREEN_HEIGHT; ++y){
  for(x = 0; x < SCREEN_WIDTH; ++x){
   SETPIX(x, y, 0);
  }
 }

}

#endif