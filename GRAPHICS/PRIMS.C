#include "GRAPHICS\PRIMS.H"

#include "GRAPHICS\VGA.H"
#include "UTIL\TYPES.H"
#include "UTIL\CONSTANTS.H"
#include "BML\BFPM\MATH.H"

void line(const vec2 start, const vec2 end, int color)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

    int x0 = start.x;
    int y0 = start.y;

    dx = ABS(end.x - start.x);
    dy = ABS(end.y - start.y);
    sx = (start.x < end.x) ? 1 : -1;
    sy = (start.y < end.y) ? 1 : -1;
    err = dx - dy;

    while(TRUE){
        SETPIX(x0, y0, color);

        if(x0 == end.x && y0 == end.y) break;

        e2 = 2 * err;

        if(e2 > -dy){
            err -= dy;
            x0 += sx;
        }

        if(e2 < dx){
            err += dx;
            y0 += sy;
        }

    }
}

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void wireTriangle(vec2 point1, vec2 point2, vec2 point3, int color)
{
	line(point1, point2, color);
	line(point2, point3, color);
	line(point3, point1, color);
}

static void filledTriangle(vec2 point1, vec2 point2, vec2 point3, int color)
{
    int totalHeight;
    int segmentHeight;

    float alpha;
    float beta;

    int ax;
    int bx;

    int x;
    int y;

    int x0 = point1.x, y0 = point1.y;
    int x1 = point2.x, y1 = point2.y;
    int x2 = point3.x, y2 = point3.y;

    if (y0 > y1) {
        swap(&x0, &x1);
        swap(&y0, &y1);
    }

    if (y0 > y2) {
        swap(&x0, &x2);
        swap(&y0, &y2);
    }

    if (y1 > y2) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }

    if (y0 == y2) return;

    totalHeight = y2 - y0;

    for (y = y0; y < y1; y++) {
        segmentHeight = y1 - y0 + 1;
        alpha = (float)(y - y0) / totalHeight;
        beta = (float)(y - y0) / segmentHeight;
        ax = x0 + (x2 - x0) * alpha;
        bx = x0 + (x1 - x0) * beta;

        if (ax > bx) swap(&ax, &bx);

        for (x = ax; x <= bx; x++) {
            SETPIX(x, y, color);
        }
    }

    for (y = y1; y <= y2; y++) {
        segmentHeight = y2 - y1 + 1;
        alpha = (float)(y - y0) / totalHeight;
        beta = (float)(y - y1) / segmentHeight;
        ax = x0 + (x2 - x0) * alpha;
        bx = x1 + (x2 - x1) * beta;

        if (ax > bx) swap(&ax, &bx);

        for (x = ax; x <= bx; x++) {
            SETPIX(x, y, color);
        }
    }
}


void triangle(vec2 point1, vec2 point2, vec2 point3, int color, BOOL filled)
{
	if(!filled) wireTriangle(point1, point2, point3, color);
	else filledTriangle(point1, point2, point3, color);
}
