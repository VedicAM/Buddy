#ifndef FIXED_H
#define FIXED_H

#include <stdint.h>

#include "UTIL\TYPES.H"

#define dp 8

// 00000000.00000000
typedef int16_t fixed;

fixed doubleToFixed(double d);
double fixedToDouble(fixed f);

fixed add(fixed a, fixed b);
fixed subtract(fixed a, fixed b);
fixed multiply(fixed a, fixed b);
fixed divide(fixed a, fixed b);

#endif
