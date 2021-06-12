#ifndef _SIMP_WINDOW_H
#define _SIMP_WINDOW_H

#include <stdbool.h>

typedef struct 
{
    Simp_Point position;
    double zoom;
} Simp_Camera;

typedef struct 
{
    void* sdl_window;
    void* sdl_renderer;
    unsigned char* eventStatus;

    Simp_Camera camera;
} Simp_Window;

typedef enum
{
    SIMP_WINDOWEVENT_NONE,
    
    SIMP_WINDOWEVENT_CLOSE,     // Request to close the window was sent
    
    SIMP_WINDOWEVENT_RESIZED,    // Window was resized
    SIMP_WINDOWEVENT_MOVED,      // Window was moved
    
    SIMP_WINDOWEVENT_TOTAL,     // Amount of events
} Simp_WindowEvent;

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
    Closes a window and frees any memory used by it.

    Args:
        - Simp_Window* window: Window to destroy.
*/
void Simp_DestroyWindow(Simp_Window* window);

/*
    Moves the window to a specified position on the screen.

    Args:
        - Simp_Window* window: The window to be moved.
        - int x: Desired x position of the window.
        - int y: Desired y position of the window.
*/
void Simp_SetWindowPosition(Simp_Window* window, int x, int y);

/*
    Resizes the window to a specified width and height.

    Args:
        - Simp_Window* window: The window to be resized.
        - int width: Desired width of the window.
        - int height: Desired height of the window.
*/
void Simp_SetWindowSize(Simp_Window *window, int width, int height);

/*
    Moves and resizes the window to match the position and dimensions a rect.

    Args:
        - Simp_Window* window: The window to be repositioned and resized.
        - Simp_Rect: The rect containing the new position and dimensions.
*/
void Simp_SetWindowRect(Simp_Window *window, Simp_Rect rect);

/*
    Sets whether or not the window can be resized by the user.

    Args:
        - Simp_Window* window: The window to modify.
        - bool resizeable: Whether or not the window should be made resizable.
*/
void Simp_SetWindowResizeable(Simp_Window* window, bool resizeable);

/*
    Sets whether or not the window should be in fullscreen mode.

    Args:
        - Simp_Window* window: The window to modify.
        - bool fullscreen: Whether or not the window should be in fullscreen mode.
*/
void Simp_SetWindowFullscreen(Simp_Window* window, bool fullscreen);

/*
    Sets whether or not the window should have a border.

    Args:
        - Simp_Window* window: The window to modify.
        - bool bordered: Whether or not the window should have a border.
*/
void Simp_SetWindowBordered(Simp_Window* window, bool bordered);

/*
    Returns the position and dimensions of a given window in the form of a Simp_Rect.
*/
Simp_Rect Simp_GetWindowRect(Simp_Window* window);

/*
    Polls all window events and returns the status of a given event.

    Args:
        - Simp_Window* window: Window to poll events from.
        - Simp_WindowEvent event: The event you would like to check.

    Returns the status of the event you would like to check.
*/
int Simp_GetWindowEventStatus(Simp_Window* window, Simp_WindowEvent event);

#endif // _SIMP_WINDOW_H
