#pragma once

#include "SDL.h"
#include <math.h>

struct Colour : SDL_Colour{
	Colour();

	Colour(Uint32 hex);

	Colour(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a = 255);

};