#ifndef _SIMP_INPUT_H
#define _SIMP_INPUT_H

typedef enum
{
    SIMP_KEY_UNKNOWN = 0,

    SIMP_KEY_A = 4,
    SIMP_KEY_B = 5,
    SIMP_KEY_C = 6,
    SIMP_KEY_D = 7,
    SIMP_KEY_E = 8,
    SIMP_KEY_F = 9,
    SIMP_KEY_G = 10,
    SIMP_KEY_H = 11,
    SIMP_KEY_I = 12,
    SIMP_KEY_J = 13,
    SIMP_KEY_K = 14,
    SIMP_KEY_L = 15,
    SIMP_KEY_M = 16,
    SIMP_KEY_N = 17,
    SIMP_KEY_O = 18,
    SIMP_KEY_P = 19,
    SIMP_KEY_Q = 20,
    SIMP_KEY_R = 21,
    SIMP_KEY_S = 22,
    SIMP_KEY_T = 23,
    SIMP_KEY_U = 24,
    SIMP_KEY_V = 25,
    SIMP_KEY_W = 26,
    SIMP_KEY_X = 27,
    SIMP_KEY_Y = 28,
    SIMP_KEY_Z = 29,

    SIMP_KEY_1 = 30,
    SIMP_KEY_2 = 31,
    SIMP_KEY_3 = 32,
    SIMP_KEY_4 = 33,
    SIMP_KEY_5 = 34,
    SIMP_KEY_6 = 35,
    SIMP_KEY_7 = 36,
    SIMP_KEY_8 = 37,
    SIMP_KEY_9 = 38,
    SIMP_KEY_0 = 39,

    SIMP_KEY_RETURN = 40,
    SIMP_KEY_ESCAPE = 41,
    SIMP_KEY_BACKSPACE = 42,
    SIMP_KEY_TAB = 43,
    SIMP_KEY_SPACE = 44,

    SIMP_KEY_MINUS = 45,
    SIMP_KEY_EQUALS = 46,
    SIMP_KEY_LEFTBRACKET = 47,
    SIMP_KEY_RIGHTBRACKET = 48,
    SIMP_KEY_BACKSLASH = 49,

    SIMP_KEY_NONUSHASH = 50,

    SIMP_KEY_SEMICOLON = 51,
    SIMP_KEY_APOSTROPHE = 52,
    SIMP_KEY_GRAVE = 53,

    SIMP_KEY_COMMA = 54,
    SIMP_KEY_PERIOD = 55,
    SIMP_KEY_SLASH = 56,

    SIMP_KEY_CAPSLOCK = 57,

    SIMP_KEY_F1 = 58,
    SIMP_KEY_F2 = 59,
    SIMP_KEY_F3 = 60,
    SIMP_KEY_F4 = 61,
    SIMP_KEY_F5 = 62,
    SIMP_KEY_F6 = 63,
    SIMP_KEY_F7 = 64,
    SIMP_KEY_F8 = 65,
    SIMP_KEY_F9 = 66,
    SIMP_KEY_F10 = 67,
    SIMP_KEY_F11 = 68,
    SIMP_KEY_F12 = 69,

    SIMP_KEY_PRINTSCREEN = 70,
    SIMP_KEY_SCROLLLOCK = 71,
    SIMP_KEY_PAUSE = 72,
    SIMP_KEY_INSERT = 73,

    SIMP_KEY_HOME = 74,
    SIMP_KEY_PAGEUP = 75,
    SIMP_KEY_DELETE = 76,
    SIMP_KEY_END = 77,
    SIMP_KEY_PAGEDOWN = 78,
    SIMP_KEY_RIGHT = 79,
    SIMP_KEY_LEFT = 80,
    SIMP_KEY_DOWN = 81,
    SIMP_KEY_UP = 82,

    SIMP_KEY_NUMLOCKCLEAR = 83,

    SIMP_KEY_KP_DIVIDE = 84,
    SIMP_KEY_KP_MULTIPLY = 85,
    SIMP_KEY_KP_MINUS = 86,
    SIMP_KEY_KP_PLUS = 87,
    SIMP_KEY_KP_ENTER = 88,
    SIMP_KEY_KP_1 = 89,
    SIMP_KEY_KP_2 = 90,
    SIMP_KEY_KP_3 = 91,
    SIMP_KEY_KP_4 = 92,
    SIMP_KEY_KP_5 = 93,
    SIMP_KEY_KP_6 = 94,
    SIMP_KEY_KP_7 = 95,
    SIMP_KEY_KP_8 = 96,
    SIMP_KEY_KP_9 = 97,
    SIMP_KEY_KP_0 = 98,
    SIMP_KEY_KP_PERIOD = 99,

    SIMP_KEY_NONUSBACKSLASH = 100,

    SIMP_KEY_APPLICATION = 101,
    SIMP_KEY_POWER = 102,

    SIMP_KEY_KP_EQUALS = 103,
    SIMP_KEY_F13 = 104,
    SIMP_KEY_F14 = 105,
    SIMP_KEY_F15 = 106,
    SIMP_KEY_F16 = 107,
    SIMP_KEY_F17 = 108,
    SIMP_KEY_F18 = 109,
    SIMP_KEY_F19 = 110,
    SIMP_KEY_F20 = 111,
    SIMP_KEY_F21 = 112,
    SIMP_KEY_F22 = 113,
    SIMP_KEY_F23 = 114,
    SIMP_KEY_F24 = 115,
    SIMP_KEY_EXECUTE = 116,
    SIMP_KEY_HELP = 117,
    SIMP_KEY_MENU = 118,
    SIMP_KEY_SELECT = 119,
    SIMP_KEY_STOP = 120,
    SIMP_KEY_AGAIN = 121,
    SIMP_KEY_UNDO = 122,
    SIMP_KEY_CUT = 123,
    SIMP_KEY_COPY = 124,
    SIMP_KEY_PASTE = 125,
    SIMP_KEY_FIND = 126,
    SIMP_KEY_MUTE = 127,
    SIMP_KEY_VOLUMEUP = 128,
    SIMP_KEY_VOLUMEDOWN = 129,

    SIMP_KEY_KP_COMMA = 133,
    SIMP_KEY_KP_EQUALSAS400 = 134,

    SIMP_KEY_INTERNATIONAL1 = 135,
    SIMP_KEY_INTERNATIONAL2 = 136,
    SIMP_KEY_INTERNATIONAL3 = 137,
    SIMP_KEY_INTERNATIONAL4 = 138,
    SIMP_KEY_INTERNATIONAL5 = 139,
    SIMP_KEY_INTERNATIONAL6 = 140,
    SIMP_KEY_INTERNATIONAL7 = 141,
    SIMP_KEY_INTERNATIONAL8 = 142,
    SIMP_KEY_INTERNATIONAL9 = 143,
    SIMP_KEY_LANG1 = 144,
    SIMP_KEY_LANG2 = 145,
    SIMP_KEY_LANG3 = 146,
    SIMP_KEY_LANG4 = 147,
    SIMP_KEY_LANG5 = 148,
    SIMP_KEY_LANG6 = 149,
    SIMP_KEY_LANG7 = 150, 
    SIMP_KEY_LANG8 = 151,
    SIMP_KEY_LANG9 = 152,

    SIMP_KEY_ALTERASE = 153,
    SIMP_KEY_SYSREQ = 154,
    SIMP_KEY_CANCEL = 155,
    SIMP_KEY_CLEAR = 156,
    SIMP_KEY_PRIOR = 157,
    SIMP_KEY_RETURN2 = 158,
    SIMP_KEY_SEPARATOR = 159,
    SIMP_KEY_OUT = 160,
    SIMP_KEY_OPER = 161,
    SIMP_KEY_CLEARAGAIN = 162,
    SIMP_KEY_CRSEL = 163,
    SIMP_KEY_EXSEL = 164,

    SIMP_KEY_KP_00 = 176,
    SIMP_KEY_KP_000 = 177,
    SIMP_KEY_THOUSANDSSEPARATOR = 178,
    SIMP_KEY_DECIMALSEPARATOR = 179,
    SIMP_KEY_CURRENCYUNIT = 180,
    SIMP_KEY_CURRENCYSUBUNIT = 181,
    SIMP_KEY_KP_LEFTPAREN = 182,
    SIMP_KEY_KP_RIGHTPAREN = 183,
    SIMP_KEY_KP_LEFTBRACE = 184,
    SIMP_KEY_KP_RIGHTBRACE = 185,
    SIMP_KEY_KP_TAB = 186,
    SIMP_KEY_KP_BACKSPACE = 187,
    SIMP_KEY_KP_A = 188,
    SIMP_KEY_KP_B = 189,
    SIMP_KEY_KP_C = 190,
    SIMP_KEY_KP_D = 191,
    SIMP_KEY_KP_E = 192,
    SIMP_KEY_KP_F = 193,
    SIMP_KEY_KP_XOR = 194,
    SIMP_KEY_KP_POWER = 195,
    SIMP_KEY_KP_PERCENT = 196,
    SIMP_KEY_KP_LESS = 197,
    SIMP_KEY_KP_GREATER = 198,
    SIMP_KEY_KP_AMPERSAND = 199,
    SIMP_KEY_KP_DBLAMPERSAND = 200,
    SIMP_KEY_KP_VERTICALBAR = 201,
    SIMP_KEY_KP_DBLVERTICALBAR = 202,
    SIMP_KEY_KP_COLON = 203,
    SIMP_KEY_KP_HASH = 204,
    SIMP_KEY_KP_SPACE = 205,
    SIMP_KEY_KP_AT = 206,
    SIMP_KEY_KP_EXCLAM = 207,
    SIMP_KEY_KP_MEMSTORE = 208,
    SIMP_KEY_KP_MEMRECALL = 209,
    SIMP_KEY_KP_MEMCLEAR = 210,
    SIMP_KEY_KP_MEMADD = 211,
    SIMP_KEY_KP_MEMSUBTRACT = 212,
    SIMP_KEY_KP_MEMMULTIPLY = 213,
    SIMP_KEY_KP_MEMDIVIDE = 214,
    SIMP_KEY_KP_PLUSMINUS = 215,
    SIMP_KEY_KP_CLEAR = 216,
    SIMP_KEY_KP_CLEARENTRY = 217,
    SIMP_KEY_KP_BINARY = 218,
    SIMP_KEY_KP_OCTAL = 219,
    SIMP_KEY_KP_DECIMAL = 220,
    SIMP_KEY_KP_HEXADECIMAL = 221,

    SIMP_KEY_LCTRL = 224,
    SIMP_KEY_LSHIFT = 225,
    SIMP_KEY_LALT = 226,
    SIMP_KEY_LGUI = 227,
    SIMP_KEY_RCTRL = 228,
    SIMP_KEY_RSHIFT = 229,
    SIMP_KEY_RALT = 230,
    SIMP_KEY_RGUI = 231,

    SIMP_KEY_MODE = 257,

    SIMP_KEY_AUDIONEXT = 258,
    SIMP_KEY_AUDIOPREV = 259,
    SIMP_KEY_AUDIOSTOP = 260,
    SIMP_KEY_AUDIOPLAY = 261,
    SIMP_KEY_AUDIOMUTE = 262,
    SIMP_KEY_MEDIASELECT = 263,
    SIMP_KEY_WWW = 264,
    SIMP_KEY_MAIL = 265,
    SIMP_KEY_CALCULATOR = 266,
    SIMP_KEY_COMPUTER = 267,
    SIMP_KEY_AC_SEARCH = 268,
    SIMP_KEY_AC_HOME = 269,
    SIMP_KEY_AC_BACK = 270,
    SIMP_KEY_AC_FORWARD = 271,
    SIMP_KEY_AC_STOP = 272,
    SIMP_KEY_AC_REFRESH = 273,
    SIMP_KEY_AC_BOOKMARKS = 274,

    SIMP_KEY_BRIGHTNESSDOWN = 275,
    SIMP_KEY_BRIGHTNESSUP = 276,
    SIMP_KEY_DISPLAYSWITCH = 277,

    SIMP_KEY_KBDILLUMTOGGLE = 278,
    SIMP_KEY_KBDILLUMDOWN = 279,
    SIMP_KEY_KBDILLUMUP = 280,
    SIMP_KEY_EJECT = 281,
    SIMP_KEY_SLEEP = 282,

    SIMP_KEY_APP1 = 283,
    SIMP_KEY_APP2 = 284,

    SIMP_KEY_AUDIOREWIND = 285,
    SIMP_KEY_AUDIOFASTFORWARD = 286,

    SIMP_KEY_TOTAL = 512
} Simp_Key;

typedef enum 
{
    SIMP_MOUSEBUTTON_LEFT = 1,
    SIMP_MOUSEBUTTON_MIDDLE = 2,
    SIMP_MOUSEBUTTON_RIGHT = 4,
} Simp_MouseButton;

/*
    Updates internal input values.

    Should be called before checking for inputs.
*/
void Simp_PollInputs(void);


/*
    Returns whether a given key is currently being held down.

    Args:
        - Simp_Key key: The given key to check.
*/
bool Simp_GetKey(Simp_Key key);

/*
    Returns whether a given key has just been pressed.

    Args:
        - Simp_Key key: The given key to check.
*/
bool Simp_GetKeyDown(Simp_Key key);

/*
    Returns whether a given key has just been released.

    Args:
        - Simp_Key key: The given key to check.
*/
bool Simp_GetKeyUp(Simp_Key key);


/*
    Returns the position of the mouse cursor relative to the window..
*/
Simp_Point Simp_GetMousePosition(void);

/*
    Returns whether a given mouse button is currently being held down.

    Args:
        - Simp_MouseButton mouseButton: The given mouse button to check.
*/
bool Simp_GetMouseButton(Simp_MouseButton mouseButton);

/*
    Returns whether a given mouse button has just been pressed.

    Args:
        - Simp_MouseButton mouseButton: The given mouse button to check.
*/
bool Simp_GetMouseButtonDown(Simp_MouseButton mouseButton);

/*
    Returns whether a given mouse button has just been released.

    Args:
        - Simp_MouseButton mouseButton: The given mouse button to check.
*/
bool Simp_GetMouseButtonUp(Simp_MouseButton mouseButton);

#endif // _SIMP_INPUT_H
