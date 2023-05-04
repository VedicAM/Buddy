#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <math.h>

typedef unsigned char byte;

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03
#define SCREEN_HEIGHT 200
#define SCREEN_WIDTH 320

byte far *VGA = (byte far *)0xA0000000L;

#define SETPIX(x, y, c) *(VGA+(x)+(y)*SCREEN_WIDTH)=c
#define GETPIX(x, y) *(VGA+(x)+(y)*SCREEN_WIDTH)


void setMode(byte mode){
 union REGS regs;
 regs.h.ah = SET_MODE;
 regs.h.al = mode;
 int86(VIDEO_INT, &regs, &regs);
}

void line(int x0, int y0, int x2, int y2){
 int dx = abs(x2 - x0);
 int dy = abs(y2 - y0);
 int sx = (x0 < x2) ? 1 : -1;
 int sy = (y0 < y2) ? 1 : -1;
 int err = dx - dy;
 int e2;

 while(x0 != x2 || y0 != y2){
  SETPIX(x0, y0, 31);
  e2 = err * 2;
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


void drawBackground(){
 int x, y;

 for(y = 0; y < SCREEN_HEIGHT; ++y){
  for(x = 0; x < SCREEN_WIDTH; ++x){
   SETPIX(x, y, 0);
  }
 }

}
/* NOTE: */
/* Nice Looking White 31 */

struct Vec3D{
 float x, y, z;
};

struct Vec3D matrixMult2x3(float projection[2][3], struct Vec3D v){
 struct Vec3D res;
 float result[2] = {0};
 int i; int j;

 for(i = 0; i < 2; i++){
  for(j = 0; j < 3; j++){
   result[i] += projection[i][j] * ((j == 0) ? v.x : ((j == 1) ? v.y : v.z));
  }
 }

 res.x = result[0];
 res.y = result[1];

 return res;

}



struct Vec3D matrixMult3x3(float projection[3][3], struct Vec3D v){
 struct Vec3D res;

 float x = projection[0][0] * v.x + projection[0][1] * v.y + projection[0][2] * v.z;
 float y = projection[1][0] * v.x + projection[1][1] * v.y + projection[1][2] * v.z;
 float z = projection[2][0] * v.x + projection[2][1] * v.y + projection[2][2] * v.z;

 res.x = x;
 res.y = y;
 res.z = z;

 return res;
}


void connect(int i, int j, struct Vec3D points[8]){
 struct Vec3D a = points[i];
 struct Vec3D b = points[j];

 line(a.x, a.y, b.x, b.y);
}

struct Vec3D points[8];
struct Vec3D projected2D;
struct Vec3D rotated;
struct Vec3D projected[8];



float rotationZ[3][3];
float rotationX[3][3];
float rotationY[3][3];

float projection[2][3];


float cosRes;
float sinRes;
float angle;

char kc;
int i, j, k;


int main(){
 angle = 0;

 kc = 0;
 setMode(VGA_256_COLOR_MODE);

 clrscr();
 drawBackground();


 cosRes = cos(angle/100);
 sinRes = sin(angle/100);

 rotationZ[0][0] = cosRes; rotationZ[0][1] = -sinRes; rotationZ[0][2] = 0;
 rotationZ[1][0] = sinRes; rotationZ[1][1] = cosRes; rotationZ[1][2] = 0;
 rotationZ[2][0] = 0; rotationZ[2][1] = 0; rotationZ[2][2] = 1;

 rotationX[0][0] = 1; rotationX[0][1] = 0; rotationX[0][2] = 0;
 rotationX[1][0] = 0; rotationX[1][1] = cosRes; rotationX[1][2] = -sinRes;
 rotationX[2][0] = 0; rotationX[2][1] = sinRes; rotationX[2][2] = cosRes;

 rotationY[0][0] = cosRes; rotationY[0][1] = 0; rotationY[0][2] = sinRes;
 rotationY[1][0] = 0; rotationY[1][1] = 1; rotationY[1][2] = 0;
 rotationY[2][0] = -sinRes; rotationY[2][1] = 0; rotationY[2][2] = cosRes;

 /* Clear the screen */
 points[0].x = 25; points[0].y = 25; points[0].z = 25;
 points[1].x = 50; points[1].y = 25; points[1].z = 25;
 points[2].x = 50; points[2].y = 50; points[2].z = 25;
 points[3].x = 25; points[3].y = 50; points[3].z = 25;
 points[4].x = 25; points[4].y = 25; points[4].z = 50;
 points[5].x = 50; points[5].y = 25; points[5].z = 50;
 points[6].x = 50; points[6].y = 50; points[6].z = 50;
 points[7].x = 25; points[7].y = 50; points[7].z = 50;

 for(i = 0; i < 8; i++){
  rotated = matrixMult3x3(rotationY, points[i]);
  rotated = matrixMult3x3(rotationX, rotated);
  rotated = matrixMult3x3(rotationZ, rotated);

  projection[0][0] = 1; projection[0][1] = 0; projection[0][2] = 0;
  projection[1][0] = 0; projection[1][1] = 1; projection[1][2] = 0;

  projected2D = matrixMult2x3(projection, rotated);
  projected[i] = projected2D;
 }

 for(j = 0; j < 8; j++){
  SETPIX((int)projected[i].x, (int)projected[i].y, 31);
 }

 for(k = 0; k < 4; k++){
  connect(k, (k + 1) % 4, projected);
  connect(k+4, ((k + 1) % 4) + 4, projected);
  connect(k, k + 4, projected);
 }



 while(kc != 0x1b){
  kc = getch();

  /* Game Loop */

 }

 setMode(TEXT_MODE);

 return 0;
}