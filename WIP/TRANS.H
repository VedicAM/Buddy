#ifndef TRANS_H
#define TRANS_H

#include <math.h>

#include "MATMATH.H"

Vec3D rotateX(Vec3D point, int angle){
 Vec3D returnPoint;

 returnPoint.x = point.x;
 returnPoint.y = cos(angle * M_PI / 180) * point.y - sin(angle * M_PI / 180) * point.z;
 returnPoint.z = sin(angle * M_PI / 180) * point.y + cos(angle * M_PI / 180) * point.z;

 return returnPoint;
}

Vec3D rotateY(Vec3D point, int angle){
 Vec3D returnPoint;

 returnPoint.x = cos(angle * M_PI / 180) * point.x - sin(angle * M_PI / 180) * point.z;
 returnPoint.y = point.y;
 returnPoint.z = sin(angle * M_PI / 180) * point.x + cos(angle * M_PI / 180);

 return returnPoint;
}

Vec3D rotateZ(Vec3D point, int angle){
 Vec3D returnPoint;

 returnPoint.x = cos(angle * M_PI / 180) * point.x - sin(angle * M_PI / 180) * point.y;
 returnPoint.y = sin(angle * M_PI / 180) * point.x + cos(angle * M_PI / 180) * point.y;
 returnPoint.z = point.z;

 return returnPoint;
}

#endif