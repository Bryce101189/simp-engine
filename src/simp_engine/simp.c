#include <SDL2/SDL.h>
#include <stdlib.h>

#include "simp.h"


// simp.h

int Simp_Init(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        Simp_SetError("Failed to initialize SDL");
        return 0;
    }

    return 1;
}

void Simp_Quit(void)
{
    Simp_FreeErrors();

    SDL_Quit();
}


// simp_window.h

Simp_Window* Simp_CreateWindow(const char* title, int width, int height)
{
    Simp_Window* window = malloc(sizeof(Simp_Window));
    window->sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    
    if(window->sdl_window == NULL)
    {
        Simp_DestroyWindow(window);
        Simp_SetError("Failed to create SDL window");
        return NULL;
    }

    window->eventStatus = calloc(1, SIMP_WINDOWEVENT_TOTAL);

    if(window->eventStatus == NULL)
    {
        Simp_DestroyWindow(window);
        Simp_SetError("Failed to reserve memory for window event storage");
        return NULL;
    }

    return window;
}

Simp_Window* Simp_CreateWindowAtPosition(const char* title, int x, int y, int width, int height)
{
    Simp_Window* window = malloc(sizeof(Simp_Window));
    window->sdl_window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
    
    if(window->sdl_window == NULL)
    {
        Simp_DestroyWindow(window);
        Simp_SetError("Failed to create SDL window");
        return NULL;
    }

    window->eventStatus = calloc(1, SIMP_WINDOWEVENT_TOTAL);

    if(window->eventStatus == NULL)
    {
        Simp_DestroyWindow(window);
        Simp_SetError("Failed to reserve memory for window event storage");
        return NULL;
    }

    return window;
}

void Simp_DestroyWindow(Simp_Window* window)
{
    if(window == NULL)
        return;

    if(window->sdl_window != NULL)
        SDL_DestroyWindow(window->sdl_window);
    
    if(window->eventStatus != NULL)
        free(window->eventStatus);

    free(window);
}

void Simp_SetWindowPosition(Simp_Window* window, int x, int y)
{
    if(window == NULL)
        return;

    SDL_SetWindowPosition(window->sdl_window, x, y);
}

void Simp_SetWindowSize(Simp_Window *window, int width, int height)
{
    if(window == NULL)
        return;

    SDL_SetWindowSize(window->sdl_window, width, height);
}

void Simp_SetWindowRect(Simp_Window *window, Simp_Rect rect)
{
    if(window == NULL)
        return;

    SDL_SetWindowPosition(window->sdl_window, (int)rect.x, (int)rect.y);
    SDL_SetWindowSize(window->sdl_window, (int)rect.width, (int)rect.height);
}

void Simp_SetWindowResizeable(Simp_Window* window, int resizeable)
{
    if(window == NULL)
        return;

    SDL_SetWindowResizable(window->sdl_window, resizeable ? SDL_TRUE : SDL_FALSE);
}

void Simp_SetWindowFullscreen(Simp_Window* window, int fullscreen)
{
    if(window == NULL)
        return;

    SDL_SetWindowFullscreen(window->sdl_window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

void Simp_SetWindowBordered(Simp_Window* window, int bordered)
{
    if(window == NULL)
        return;

    SDL_SetWindowBordered(window->sdl_window, bordered ? SDL_TRUE : SDL_FALSE);
}

Simp_Rect Simp_GetWindowRect(Simp_Window* window)
{
    Simp_Rect rect;

    if(window == NULL)
        return rect;

    int x, y, width, height;
    SDL_GetWindowPosition(window->sdl_window, &x, &y);
    SDL_GetWindowSize(window->sdl_window, &width, &height);
    
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
    
    return rect;
}

unsigned char Simp_GetWindowEventStatus(Simp_Window* window, Simp_WindowEvent event)
{
    // Update events
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_WINDOWEVENT)
        {
            switch(e.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                window->eventStatus[SIMP_WINDOWEVENT_CLOSE] = 1;
                break;

            case SDL_WINDOWEVENT_RESIZED:
                window->eventStatus[SIMP_WINDOWEVENT_RESIZED] = 1;
                break;

            case SDL_WINDOWEVENT_MOVED:
                window->eventStatus[SIMP_WINDOWEVENT_MOVED] = 1;
                break;

            default:
                break;
            }
        }
    }

    unsigned char status = window->eventStatus[event];
    window->eventStatus[event] = 0;
    return status;
}


// simp_error.h

typedef struct
{
    const char* string;
    void* next;
} _LinkedString;

_LinkedString* _errors = NULL;

void Simp_SetError(const char* errorMessage)
{
    _LinkedString* newError = malloc(sizeof(_LinkedString));

    newError->string = errorMessage;
    newError->next = _errors;
    
    _errors = newError;
}

const char* Simp_GetError(void)
{
    if(_errors == NULL)
        return NULL;

    _LinkedString* error = _errors;
    const char* errorMessage = error->string;
    _errors = error->next;
    free(error);
    
    return errorMessage;
}

int Simp_FreeErrors(void)
{
    int i = 0;
    while(_errors != NULL)
    {
        _LinkedString* error = _errors;
        _errors = error->next;
        free(error);
        ++i;
    }

    return i;
}
