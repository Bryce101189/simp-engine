#ifndef _SIMP_TYPES_H
#define _SIMP_TYPES_H

typedef struct
{
    double x, y;
} Simp_Point;

typedef struct
{
    double x, y;
    double width, height;
} Simp_Rect;

typedef struct 
{
    unsigned char r, g, b, a;
} Simp_Color;

#endif // _SIMP_TYPES_H
