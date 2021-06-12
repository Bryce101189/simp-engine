#ifndef _SIMP_FONT_H
#define _SIMP_FONT_H

#include "simp_types.h"

typedef struct
{
    void* ttf_font;
    Simp_Color color;
} Simp_Font;

/*
    Loads a font to be used to draw text.

    Args:
        char* path: Font location.
        int size: Font point size.

    Returns a valid pointer on success or NULL on error.
*/
Simp_Font* Simp_LoadFont(char* path, int size);

/*
    Destroys a font, freeing up any memory used to store it.

    Args:
        - Simp_Font* font: Font to destroy.
*/
void Simp_DestroyFont(Simp_Font* font);

#endif // _SIMP_FONT_H
