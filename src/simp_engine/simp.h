#ifndef __SIMP_H__
#define __SIMP_H__

#include <stdbool.h>

#include "simp_types.h"
#include "simp_window.h"
#include "simp_input.h"
#include "simp_error.h"

/*
    Initializes Simp Engine.

    Returns true on success or false on error.
*/
bool Simp_Init(void);

/*
    Frees up any memory allocated by Simp Engine.
*/
void Simp_Quit(void);

#endif
