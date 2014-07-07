#include "colour.h"

Colour::Colour(){
	r = 0;
	g = 0;
	b = 0;
	a = 255;
}

Colour::Colour(Uint32 hex){
	r = floor(hex / (256.0 * 256.0 * 256.0));
	g = floor(hex / (256.0 * 256.0) - r * (256.0 * 256.0 * 256.0));
	b = floor(hex / (256.0) - (r * (256.0 * 256.0 * 256.0) + b * (256.0 * 256.0)));
	a = floor(hex - (r * (256.0 * 256.0 * 256.0) + b * (256.0 * 256.0) + g * (256.0)));
}

Colour::Colour(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a){
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}