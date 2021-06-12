#ifndef _SIMP_ERROR_H
#define _SIMP_ERROR_H

/*
    Pushes an error message onto the error stack.

    Args:
        - const char* errorMessage: Message to push onto the error stack.
*/
void Simp_SetError(const char* format, ...);

/*
    Pops an error message off of the error stack and returns it.

    Returns the last error message to be pushed onto the error stack using Simp_SetError() or NULL if there are none.
*/
const char* Simp_GetError(void);

/*
    Frees all error messages that were pushed onto the error stack using Simp_SetError().
    
    Returns the number of error messages freed.
*/
int Simp_FreeErrors(void);

#endif // _SIMP_ERROR_H
