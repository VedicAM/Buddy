#ifndef TRANS_H
#define TRANS_H

#include <math.h>

#include "MATMATH.H"

Vec3D rotateY(Vec3D point){
 Vec3D returnPoint;
 int angle = 20;

 returnPoint.x = cos(angle * M_PI / 180) * point.x - sin(angle * M_PI / 180) * point.z;
 returnPoint.y = point.y;
 returnPoint.z = sin(angle * M_PI / 180) * point.x + cos(angle * M_PI / 180);

 return returnPoint;
}

#endif
