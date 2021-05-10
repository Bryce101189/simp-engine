#ifndef __SIMP_TYPES_H__
#define __SIMP_TYPES_H__

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

#endif
