#include <conio.h>
#include <stdio.h>
#include <math.h>

#include "DRAWING.H"

typedef struct{ int x, y, z; }Vec3D;
typedef struct{ int start, end; }Indices;

int kc = 0;

int fov = 10;

Vec3D points[] = {{25, 25, 25}, {25, 25, 50},
		  {50, 25, 25}, {25, 50, 25},
		  {25, 50, 50}, {50, 25, 50},
		  {50, 50, 25}, {50, 50, 50}};

Indices indices[] = {{0, 1}, {0, 2}, {0, 3},
		     {2, 5}, {3, 6}, {3, 4},
		     {4, 7}, {6, 7}, {7, 5},
		     {5, 1}, {4, 1}, {2, 6}};

Vec3D rotateX(Vec3D point){
 Vec3D returnPoint;
 int angle = 20;
 returnPoint.x = point.x;
 returnPoint.y = cos(angle * M_PI / 180) * point.y - sin(angle * M_PI / 180) * point.z;
 returnPoint.z = sin(angle * M_PI / 180) * point.y + cos(angle * M_PI / 180) * point.z;

 return returnPoint;
}

Vec3D rotateY(Vec3D point){
 Vec3D returnPoint;
 int angle = 20;
 returnPoint.x = cos(angle * M_PI / 180) * point.x - sin(angle * M_PI / 180) * point.z;
 returnPoint.y = point.y;
 returnPoint.z = sin(angle * M_PI / 180) * point.x + cos(angle * M_PI / 180) * point.z;

 return returnPoint;
}

void render(){
 int i;

 Vec3D rotatedStartPoint;
 Vec3D rotatedEndPoint;

 for(i = 0; i < sizeof(indices) / sizeof(indices[0]); i++){
  rotatedStartPoint = rotateX(rotateY(points[indices[i].start]));
  rotatedEndPoint = rotateX(rotateY(points[indices[i].end]));
  line(rotatedStartPoint.x, rotatedStartPoint.y, rotatedEndPoint.x, rotatedEndPoint.y, WHITE);
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