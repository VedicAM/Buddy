#include <conio.h>
#include <stdio.h>
#include <math.h>

#include "DRAWING.H"
#include "UTIL.H"
#include "MATMATH.H"
#include "TRANS.H"

/* Models */
#include "HOMETREE.H"

int kc = 0;


Vec3D points[sizeof(houseTreeVerts)];

int indices[sizeof(houseTreeIndices)];

int projectedPointsX[1024];
int projectedPointsY[1024];

float projection[2][3] = {{1/0.35, 0, 0},
			{0, 1/0.35, 0}};

void render(){
 int i; int j;
 float angle = 0;
 Vec3D projected2D;
 Vec3D rotated;

 for(i = 0; i < sizeof(points)/sizeof(points[0]); i++){
  rotated = rotateZ(points[i], angle);
  rotated = rotateX(rotated, angle);
  projected2D = matmul2x3(projection, rotated);

  projectedPointsX[i] = projected2D.x;
  projectedPointsY[i] = projected2D.y;
 }

 for(j = 0; j < sizeof(indices) / sizeof(indices[0]); j+=3){
  wireTriangle(projectedPointsX[indices[j]], projectedPointsY[indices[j]], projectedPointsX[indices[j+1]], projectedPointsY[indices[j+1]], projectedPointsX[indices[j+2]], projectedPointsY[indices[j+2]], WHITE);
 }
}


int i;

int main(){
 setMode(VGA_256_COLOR_MODE);

 clrscr();
 drawBackground();

 for (i = 0; i < sizeof(houseTreeVerts) / sizeof(houseTreeVerts[0]); i++) {
  points[i] = houseTreeVerts[i];
 }

 for (i = 0; i < sizeof(houseTreeIndices) / sizeof(houseTreeIndices[0]); i++) {
  indices[i] = houseTreeIndices[i];
 }

 render();

 while(kc != 0x1b){
  kc = getch();
  /* Game Loop */
 }

 setMode(TEXT_MODE);
 return 0;
}