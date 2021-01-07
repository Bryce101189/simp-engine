#ifndef __SIMP_WINDOW_H__
#define __SIMP_WINDOW_H__

typedef struct 
{
    void* sdl_window;   // void* rather than an SDL_Window* to avoid needing to include SDL.h in this header, junking it up
} Simp_Window;

/*
    Creates a window.
    If you would like to specify the position of the window try using Simp_CreateWindowAtPosition().

    Args:
        - const char* title: Window title.
        - int width: Width of the window.
        - int height: Height of the window.

    Returns a valid pointer on success or NULL on error.
*/
Simp_Window* Simp_CreateWindow(const char* title, int width, int height);

/*
    Creates a window at a specified position on the screen.
    If you do not care where the window is positioned try using Simp_CreateWindow().

    Args:
        - const char* title: Window title.
        - int width: Width of the window.
        - int height: Height of the window.

    Returns a valid pointer on success or NULL on error.
*/
Simp_Window* Simp_CreateWindowAtPosition(const char* title, int x, int y, int width, int height);

/*
    Closes a window and frees any memory used by it.

    Args:
        - Simp_Window* window: Window to destroy.
*/
void Simp_DestroyWindow(Simp_Window* window);

#endif
