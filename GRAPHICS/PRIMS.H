#ifndef PRIMS_H
#define PRIMS_H

#include "UTIL/TYPES.H"

void line(const vec2 start, const vec2 end, int color);
static void swap(int *a, int *b);
static void wireTriangle(vec2 point1, vec2 point2, vec2 point3, int color);
static void filledTriangle(vec2 point1, vec2 point2, vec2 point3, int color);
void triangle(vec2 point1, vec2 point2, vec2 point3, int color, BOOL filled);

#endif
