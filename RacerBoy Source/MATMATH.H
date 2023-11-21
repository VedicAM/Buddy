#ifndef MATMATH_H
#define MATMATH_H

typedef struct Vec3D{ float x, y, z; } Vec3D;
typedef struct Mat4x4{ float m[4][4]; } Mat4x4;

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

Vec3D matmul3x3(float m[3][3], Vec3D v){
 Vec3D res;

 float x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
 float y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
 float z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;

 res.x = x;
 res.y = y;
 res.z = z;

 return res;
}

Mat4x4 createTransMat(float x, float y, float z){
 Mat4x4 transMat;

    transMat.m[0][0] = 1.0f;
    transMat.m[0][1] = 0.0f;
    transMat.m[0][2] = 0.0f;
    transMat.m[0][3] = x;

    transMat.m[1][0] = 0.0f;
    transMat.m[1][1] = 1.0f;
    transMat.m[1][2] = 0.0f;
    transMat.m[1][3] = y;

    transMat.m[2][0] = 0.0f;
    transMat.m[2][1] = 0.0f;
    transMat.m[2][2] = 1.0f;
    transMat.m[2][3] = z;

    transMat.m[3][0] = 0.0f;
    transMat.m[3][1] = 0.0f;
    transMat.m[3][2] = 0.0f;
    transMat.m[3][3] = 1.0f;

 return transMat;
}

void applyTransMat(Vec3D *point, Mat4x4 *matrix) {
    int i;
    int j;
    float result[4];
    float conPoint[4];
    conPoint[0] = point->x;
    conPoint[1] = point->y;
    conPoint[2] = point->z;
    conPoint[3] = 1.0f;


    for (i = 0; i < 4; ++i) {
	result[i] = 0.0f;
	for(j = 0; j < 4; ++j) {
    	result[i] += matrix->m[i][j] * conPoint[j];
     }
    }

    point->x = result[0];
    point->y = result[1];
    point->z = result[2];
}

#endif