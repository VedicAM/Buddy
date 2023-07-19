
#include <conio.h>
#include <stdio.h>
#include <math.h>

#include "DRAWING.H"
#include "MATMATH.H"
#include "TRANS.H"

int kc = 0;

int fov = 10;

Vec3D points[] = {{25, 25, 25}, {25, 25, 50},
		  {50, 25, 25}, {25, 50, 25},
		  {25, 50, 50}, {50, 25, 50},
		  {50, 50, 25}, {50, 50, 50}};

float projection[2][3] = {{1, 0, 0},
			{0, 1, 0}};

void render(){
 int i;
 Vec3D projected2D;
 Vec3D rotated;

 for(i = 0; i < sizeof(points)/sizeof(points[0]); i++){
  rotated = rotateY(points[i]);
  projected2D = matmul2x3(projection, rotated);

  SETPIX(projected2D.x, projected2D.y, WHITE);
 }
}


int main(){
 setMode(VGA_256_COLOR_MODE);

 clrscr();
 drawBackground();

 render();

 while(kc != 0x1b){
  kc = getch();

  /* Game Loop */


 }
 setMode(TEXT_MODE);
 return 0;
}