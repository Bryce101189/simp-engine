#ifndef _SIMP_RENDER_H
#define _SIMP_RENDER_H

#include "simp_window.h"
#include "simp_sprite.h"
#include "simp_types.h"

/*
    Sets the clear color of a window.

    Args:
        - Simp_Window* window: Window to be modified.
        - Simp_Color color: Clear color.
*/
void Simp_SetClearColor(Simp_Window* window, Simp_Color color);

/*
    Clears the window screen.

    Args:
        - Simp_Window* window: Window to be cleared.
*/
void Simp_ClearScreen(Simp_Window* window);

/*
    Swaps the render buffer, displaying all changes made to the hidden buffer.

    Args:
        - Simp_Window* window: Window to be updated.
*/
void Simp_UpdateScreen(Simp_Window* window);

/*
    Draws a sprite to a specified window.

    Args:
        - Simp_Window* window: Window to draw the sprite to.
        - Simp_Sprite* sprite: Sprite to be drawn.
*/
void Simp_DrawSprite(Simp_Window* window, Simp_Sprite* sprite);

#endif // _SIMP_RENDER_H
