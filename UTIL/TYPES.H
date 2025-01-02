#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef unsigned char byte;

typedef struct vec3{ double x, y, z; } vec3;
typedef struct vec2{ int x, y; } vec2;
typedef struct mat4x4{ double m[4][4]; } mat4x4;
typedef struct mat2x3{ double m[2][3]; } mat2x3;

#endif
