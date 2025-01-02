#include <stdio.h>
#include <conio.h>
#include <dos.h>

#include "UTIL\TYPES.H"
#include "UTIL\CONSTANTS.H"

#include "GRAPHICS\VGA.H"
#include "GRAPHICS\PRIMS.H"
#include "GRAPHICS\COLORS.H"

#include "BML\BFPM\FIXED.H"

struct vec2 point = {0, 0};
struct vec2 point2 = {319, 0};
struct vec2 point3 = {0, 199};

struct vec2 pointB = {319, 0};
struct vec2 pointB2 = {319, 199};
struct vec2 pointB3 = {0, 199};

fixed a;
fixed b;
fixed c;

int main()
{
	char kc = 0;
	setMode(VGA_256_COLOR_MODE);

	clear(BLACK);
/*
	triangle(point, point2, point3, WHITE, TRUE);
	triangle(pointB, pointB2, pointB3, TEAL, TRUE);
*/

	a = doubleToFixed(3.5);
	b = doubleToFixed(3.5);
	c = divide(a, b);
/*
	while(kc != 0x1b)
	{
		if(kbhit())
		{
			kc = getch();
			printf("Key pressed: %02x\n", kc);
		}
	}*/

	printf("%lf", fixedToDouble(c));

	setMode(TEXT_MODE);

	return 0;
}
