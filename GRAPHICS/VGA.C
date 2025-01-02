#include "GRAPHICS\VGA.H"

#include "UTIL\TYPES.H"
#include "UTIL\CONSTANTS.H"

#include <dos.h>

void setMode(byte mode)
{
	union REGS regs;
	regs.h.ah = SET_MODE;
	regs.h.al = mode;
	int86(VIDEO_INT, &regs, &regs);
}

void clear(int COLOR)
{
	int x, y;

	for(y = 0; y < SCREEN_HEIGHT; y++)
	{
		for(x = 0; x < SCREEN_WIDTH; x++)
		{
			SETPIX(x, y, COLOR);
		}
	}
}
