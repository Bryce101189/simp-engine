#ifndef __SIMP_H__
#define __SIMP_H__

#include "simp_error.h"

/*
    Initializes Simp Engine.

    Returns 1 on success or 0 on error.
*/
int Simp_Init(void);

/*
    Frees up any memory allocated by Simp Engine.
*/
void Simp_Quit(void);

#endif
