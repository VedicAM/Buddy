#ifndef VECTORS_H
#define VECTORS_H

#include "UTIL\TYPES.H"
#include <stdint.h>

int32_t wefwef;

vec2 vec2Subtract(vec2 a, vec2 b);
vec2 vec2Add(vec2 a, vec2 b);
vec2 vec2Multiply(vec2 a, vec2 b);
vec2 vec2Divide(vec2 a, vec2 b);

vec2 vec2ScalarSubtract(vec2 a, int b);
vec2 vec2ScalarAdd(vec2 a, int b);
vec2 vec2ScalarMultiply(vec2 a, int b);
vec2 vec2ScalarDivide(vec2 a, int b);

vec3 vec3Subtract(vec3 a, vec3 b);
vec3 vec3Add(vec3 a, vec3 b);
vec3 vec3Multiply(vec3 a, vec3 b);
vec3 vec3Divide(vec3 a, vec3 b);

vec3 vec3ScalarSubtract(vec3 a, int b);
vec3 vec3ScalarAdd(vec3 a, int b);
vec3 vec3ScalarMultiply(vec3 a, int b);
vec3 vec3ScalarDivide(vec3 a, int b);

#endif
