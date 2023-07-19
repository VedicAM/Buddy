#ifndef MATMATH_H
#define MATMATH_H

typedef struct { int x, y, z; } Vec3D;

Vec3D matmul2x3(float m[2][3], Vec3D v){
 Vec3D res;

 float result[2] = {0};
 int i; int j;

 for(i = 0; i < 2; i++){
  for(j = 0; j < 3; j++){
   result[i] += m[i][j] * ((j == 0) ? v.x : ((j == 1) ? v.y : v.z));
  }
 }

 res.x = result[0];
 res.y = result[1];

 return res;
}
#endif
