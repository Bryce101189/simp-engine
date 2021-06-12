#ifndef _SIMP_TIME_H
#define _SIMP_TIME_H

/*
    Returns how many milliseconds have elapsed since Simp Engine was initialized.
*/
long Simp_GetMillisecondsElapsed(void);

/*
    Returns how many seconds have elapsed since Simp Engine was initialized.
*/
long Simp_GetSecondsElapsed(void);

/*
    Halt program execution for 'x' milliseconds.

    Args:
        - long milliseconds: How long to halt program execution for in milliseconds.
*/
void Simp_DelayMilliseconds(long milliseconds);
/*
    Halt program execution for 'x' seconds.

    Args:
        - long seconds: How long to halt program execution for in seconds.
*/
void Simp_DelaySeconds(long seconds);

#endif // _SIMP_TIME_H