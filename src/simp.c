#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdarg.h>

#include "simp.h"

static SDL_Renderer* globRenderContext = NULL;

// simp_window.h

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

    window->sdl_renderer = SDL_CreateRenderer(window->sdl_window, -1, SDL_RENDERER_ACCELERATED);

    if(window->sdl_renderer == NULL)
    {
        Simp_DestroyWindow(window);
        Simp_SetError("Failed to create SDL renderer");
        return NULL;
    }

    SDL_SetRenderDrawColor(window->sdl_renderer, 0, 0, 0, 255);
    SDL_SetRenderDrawBlendMode(window->sdl_renderer, SDL_BLENDMODE_BLEND);  // Render opacity

    if(globRenderContext == NULL)
        globRenderContext = window->sdl_renderer;

    window->eventStatus = calloc(sizeof(int), SIMP_WINDOWEVENT_TOTAL);

    if(window->eventStatus == NULL)
    {
        Simp_DestroyWindow(window);
        Simp_SetError("Failed to reserve memory for window event storage");
        return NULL;
    }

    window->camera.position.x = 0;
    window->camera.position.y = 0;
    window->camera.zoom = 1.0;

    return window;
}

Simp_Window* Simp_CreateWindow(const char* title, int width, int height)
{
    return Simp_CreateWindowAtPosition(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height);
}

void Simp_DestroyWindow(Simp_Window* window)
{
    if(window == NULL)
        return;

    if(window->sdl_window != NULL)
        SDL_DestroyWindow(window->sdl_window);
    
    if(window->sdl_renderer != NULL)
        SDL_DestroyRenderer(window->sdl_renderer);

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

void Simp_SetWindowResizeable(Simp_Window* window, bool resizeable)
{
    if(window == NULL)
        return;

    SDL_SetWindowResizable(window->sdl_window, resizeable ? SDL_TRUE : SDL_FALSE);
}

void Simp_SetWindowFullscreen(Simp_Window* window, bool fullscreen)
{
    if(window == NULL)
        return;

    SDL_SetWindowFullscreen(window->sdl_window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

void Simp_SetWindowBordered(Simp_Window* window, bool bordered)
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

int Simp_GetWindowEventStatus(Simp_Window* window, Simp_WindowEvent event)
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

    int status = window->eventStatus[event];
    window->eventStatus[event] = 0;
    return status;
}


// simp_font.h

Simp_Font* Simp_LoadFont(char* path, int size)
{
    if(size <= 0)
    {
        Simp_SetError("Invalid font size of %d provided", size);
        return NULL;
    }

    TTF_Font* ttf_font = TTF_OpenFont(path, size);

    if(ttf_font == NULL)
    {
        Simp_SetError("Unable to load font '%s'", path);
        return NULL;
    }

    Simp_Font* font = malloc(sizeof(Simp_Font));

    font->ttf_font = ttf_font;
    
    Simp_Color white = { 255, 255, 255, 255 };
    font->color = white;

    return font;
}

void Simp_DestroyFont(Simp_Font* font)
{
    if(font == NULL)
        return;

    if(font->ttf_font != NULL)
        TTF_CloseFont(font->ttf_font);

    free(font);
}


// simp_sprite.h

Simp_Sprite* Simp_CreateSprite(int width, int height)
{
    if(width <= 0 || height <= 0)
    {
        Simp_SetError("Invalid dimensions of %dx%d provided", width, height);
        return NULL;
    }

    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

    if(surface == NULL)
    {
        Simp_SetError("Failed to create SDL surface");
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(globRenderContext, surface);

    if(texture == NULL)
    {
        Simp_SetError("Failed to create SDL texture from SDL surface");
        return NULL;
    }

    Simp_Sprite* sprite = malloc(sizeof(Simp_Sprite));

    sprite->sdl_surface = surface;
    sprite->sdl_texture = texture;

    Simp_Rect src_rect = { 0, 0, surface->w, surface->h };
    sprite->src_rect = src_rect;

    sprite->position.x = 0;
    sprite->position.y = 0;

    sprite->rotation = 0;
    sprite->scale = 1.0;

    return sprite;
}

Simp_Sprite* Simp_CreateSpriteFromImage(char* path)
{
    SDL_Surface* surface = IMG_Load(path);
 
    if(surface == NULL)
    {
        Simp_SetError("Failed to create SDL surface from image at '%s'", path);
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(globRenderContext, surface);
    
    if(texture == NULL)
    {
        Simp_SetError("Failed to create SDL texture from SDL surface");
        return NULL;
    }

    Simp_Sprite* sprite = malloc(sizeof(Simp_Sprite));
    sprite->sdl_surface = surface;
    sprite->sdl_texture = texture;

    Simp_Rect src_rect = { 0, 0, surface->w, surface->h };
    sprite->src_rect = src_rect;

    sprite->position.x = 0;
    sprite->position.y = 0;

    sprite->rotation = 0;
    sprite->scale = 1.0;

    return sprite;
}

Simp_Sprite* Simp_CreateSpriteFromText(Simp_Font* font, char* text)
{
    SDL_Color col = { font->color.r, font->color.g, font->color.b, font->color.a };
    SDL_Surface* surface = TTF_RenderText_Blended(font->ttf_font, text, col);
 
    if(surface == NULL)
    {
        Simp_SetError("Failed to create SDL surface from text '%s'", text);
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(globRenderContext, surface);
    
    if(texture == NULL)
    {
        Simp_SetError("Failed to create SDL texture from SDL surface");
        return NULL;
    }

    Simp_Sprite* sprite = malloc(sizeof(Simp_Sprite));
    sprite->sdl_surface = surface;
    sprite->sdl_texture = texture;

    Simp_Rect src_rect = { 0, 0, surface->w, surface->h };
    sprite->src_rect = src_rect;

    sprite->position.x = 0;
    sprite->position.y = 0;

    sprite->rotation = 0;
    sprite->scale = 1.0;

    return sprite;
}

void Simp_BlitSprite(Simp_Sprite* src, Simp_Rect src_rect, Simp_Sprite* dest, Simp_Rect dest_rect)
{
    SDL_Rect sdl_src_rect = { src_rect.x, src_rect.y, src_rect.width, src_rect.height };
    SDL_Rect sdl_dest_rect = { dest_rect.x, dest_rect.y, dest_rect.width, dest_rect.height };

    SDL_BlitSurface(src->sdl_surface, &sdl_src_rect, dest->sdl_surface, &sdl_dest_rect);
    dest->sdl_texture = SDL_CreateTextureFromSurface(globRenderContext, dest->sdl_surface);
}

void Simp_DestroySprite(Simp_Sprite* sprite)
{
    if(sprite == NULL)
        return;

    if(sprite->sdl_surface != NULL)
        SDL_FreeSurface(sprite->sdl_surface);

    if(sprite->sdl_texture != NULL)
        SDL_DestroyTexture(sprite->sdl_texture);

    free(sprite);
}


// simp_render.h

void Simp_SetClearColor(Simp_Window* window, Simp_Color color)
{
    SDL_SetRenderDrawColor(window->sdl_renderer, color.r, color.g, color.b, color.a);
}

void Simp_ClearScreen(Simp_Window* window)
{
    SDL_RenderClear(window->sdl_renderer);
}

void Simp_UpdateScreen(Simp_Window* window)
{
    SDL_RenderPresent(window->sdl_renderer);
}

void Simp_DrawSprite(Simp_Window* window, Simp_Sprite* sprite)
{    
    const int spriteWidth = sprite->src_rect.width * sprite->scale * window->camera.zoom;
    const int spriteHeight = sprite->src_rect.height * sprite->scale * window->camera.zoom;
    
    const int xPos = (sprite->position.x * window->camera.zoom)
        + (Simp_GetWindowRect(window).width / 2)
        - (window->camera.position.x)
        - (spriteWidth / 2);
    
    const int yPos = (-sprite->position.y * window->camera.zoom)
        + (Simp_GetWindowRect(window).height / 2)
        - (-window->camera.position.y)
        - (spriteHeight / 2);

    SDL_Rect src_rect = 
    { 
        sprite->src_rect.x, sprite->src_rect.y,
        sprite->src_rect.width, sprite->src_rect.height
    };

    SDL_Rect dst_rect = { xPos, yPos, spriteWidth, spriteHeight };

    SDL_RenderCopyEx(window->sdl_renderer, sprite->sdl_texture, &src_rect, &dst_rect, sprite->rotation, NULL, SDL_FLIP_NONE);
}


// simp_input.h

static Uint8* keyState = NULL;
static Uint8* prevKeyState = NULL;
static int mouseX, mouseY, prevMouseX, prevMouseY;
static int buttonMask, prevButtonMask;

void Simp_PollInputs(void)
{
    int numKeys;
    const Uint8* keys = SDL_GetKeyboardState(&numKeys);

    for(int key = 0; key < numKeys; ++key)
    {
        prevKeyState[key] = keyState[key];
        keyState[key] = keys[key];
    }

    prevMouseX = mouseX;
    prevMouseY = mouseY;
    prevButtonMask = buttonMask;

    buttonMask = SDL_GetMouseState(&mouseX, &mouseY);
}

bool Simp_GetKey(Simp_Key key)
{
    if(keyState[key])
        return true;

    return false;
}

bool Simp_GetKeyDown(Simp_Key key)
{
    if(keyState[key] && !prevKeyState[key])
        return true;

    return false;
}

bool Simp_GetKeyUp(Simp_Key key)
{
    if(!keyState[key] && prevKeyState[key])
        return true;
    
    return false;
}

Simp_Point Simp_GetMousePosition(void)
{
    Simp_Point p = { mouseX, mouseY };
    return p;
}

bool Simp_GetMouseButton(Simp_MouseButton mouseButton)
{
    if(buttonMask & mouseButton)
        return true;
    
    return false;
}

bool Simp_GetMouseButtonDown(Simp_MouseButton mouseButton)
{
    if(buttonMask & mouseButton && !(prevButtonMask & mouseButton))
        return true;
    
    return false;
}

bool Simp_GetMouseButtonUp(Simp_MouseButton mouseButton)
{
    if(!(buttonMask & mouseButton) && prevButtonMask & mouseButton)
        return true;

    return false;
}


// simp_error.h

typedef struct
{
    const char* string;
    void* next;
} LinkedString;

static LinkedString* errors = NULL;

void Simp_SetError(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    
    LinkedString* newError = malloc(sizeof(LinkedString));

    char buffer[0x1000];
    int len = vsprintf(buffer, format, args);
    buffer[len] = '\0';

    newError->string = buffer;
    newError->next = errors;
    
    errors = newError;
}

const char* Simp_GetError(void)
{
    if(errors == NULL)
        return NULL;

    LinkedString* error = errors;
    const char* errorMessage = error->string;
    errors = error->next;
    free(error);
    
    return errorMessage;
}

int Simp_FreeErrors(void)
{
    int i = 0;
    while(errors != NULL)
    {
        LinkedString* error = errors;
        errors = error->next;
        free(error);
        ++i;
    }

    return i;
}


// simp.h

bool Simp_Init(void)
{
    // Initialize SDL2 and it's subsystems
    if(SDL_Init(SDL_INIT_VIDEO) != false)
    {
        Simp_SetError("Failed to initialize SDL2");
        return false;
    }

    // Initialize SDL2_image
    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;

    if(IMG_Init(imgFlags) != imgFlags)
    {
        Simp_SetError("Failed to initialize SDL2_image");
        return false;
    }

    // Initialize SDL2_ttf
    if(TTF_Init() == -1)
    {
        Simp_SetError("Failed to initialize SDL2_ttf");
        return false;
    }

    // Allocate memory for keyboard states
    keyState = calloc(SIMP_KEY_TOTAL, sizeof(Uint8));
    prevKeyState = calloc(SIMP_KEY_TOTAL, sizeof(Uint8));

    if(prevKeyState == NULL)
    {
        Simp_SetError("Failed to allocate memory for prevKeyState");
        return false;
    }

    return true;
}

void Simp_Quit(void)
{
    Simp_FreeErrors();

    free(keyState);
    free(prevKeyState);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
