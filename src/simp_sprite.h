#ifndef _SIMP_SPRITE_H
#define _SIMP_SPRITE_H

#include "simp_types.h"

typedef struct
{
    void* sdl_surface;
    void* sdl_texture;
    Simp_Rect src_rect;
    
    Simp_Point position;
    double rotation;
    double scale;
} Simp_Sprite;

/*
    Creates a blank sprite with a specified width and height.

    Args:
        - int width: Width of the sprite.
        - int height: Height of the sprite.

    Returns a valid pointer on success or NULL on error.
*/
Simp_Sprite* Simp_CreateSprite(int width, int height);

/*
    Creates a sprite from a locally stored image.

    Args:
        - char* path: Image location.

    Returns a valid pointer on success or NULL on error.
*/
Simp_Sprite* Simp_CreateSpriteFromImage(char* path);

/*
    Creates a sprite from a font and user defined text.

    Args:
        - Simp_Font* font: Font to use.
        - char* text: User defined text.

    Returns a valid pointer on success or NULL on error.
*/
Simp_Sprite* Simp_CreateSpriteFromText(Simp_Font* font, char* text);

/*
    Destroys a sprite, freeing up any memory used to store it.

    Args:
        - Simp_Sprite* sprite: Sprite to destroy.
*/
void Simp_DestroySprite(Simp_Sprite* sprite);

/*
    Copys a portion of one sprite to another.

    Args:
        Simp_Sprite* src: Source sprite.
        Simp_Rect src_rect: Portion of source sprite to be copied.
        Simp_Sprite* dest: Destination sprite.
        Simp_Rect dest_rect: Where the portion should be copied to.

    Returns a valid pointer on success or NULL on error.
*/
void Simp_BlitSprite(Simp_Sprite* src, Simp_Rect src_rect, Simp_Sprite* dest, Simp_Rect dest_rect);

#endif // _SIMP_SPRITE_H
