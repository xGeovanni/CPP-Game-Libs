#pragma once

#include "Vector.h"
#include <vector>
#include "SDL.h"

SDL_Point makePoint(int x, int y);

class Shape{
};

class Circle;

class Rect : Shape, private SDL_Rect{

	void updateDrawValues();

	public:

		Vector2 pos;
		Vector2 size;

		Rect();

		Rect(float _x, float _y, float _w, float _h);

		Rect(Vector2 _pos, Vector2 _size);

		void draw(SDL_Renderer *renderer, bool fill);

		bool collideRect(Rect *const other);

		bool collideCircle(Circle *const other);
};

struct Circle : Shape{
	Vector2 centre;
	float radius;

	Circle();

	Circle(Vector2 _centre, float _radius);

	bool collideCircle(Circle *const other);

	bool collideRect(Rect *const other);

	void draw(SDL_Renderer *renderer, bool fill);
};