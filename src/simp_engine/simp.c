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
