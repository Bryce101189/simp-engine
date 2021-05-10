#ifndef _SIMP_H
#define _SIMP_H

#include <stdbool.h>

#include "simp_error.h"
#include "simp_font.h"
#include "simp_input.h"
#include "simp_render.h"
#include "simp_sprite.h"
#include "simp_types.h"
#include "simp_window.h"

/*
    Initializes Simp Engine.

    Returns true on success or false on error.
*/
bool Simp_Init(void);

/*
    Frees up any memory allocated by Simp Engine.
*/
void Simp_Quit(void);

#endif // _SIMP_H
