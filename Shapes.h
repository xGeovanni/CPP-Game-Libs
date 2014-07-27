#pragma once

#include "Vector.h"
#include <vector>
#include "SDL.h"

struct Circle;
class Rect;

SDL_Point makePoint(int x, int y);

enum ShapeType{
	circle,
	rect,
};

class Shape{

public:
	Vector2 pos;
	ShapeType type;

	bool collide(Shape *const other);
	virtual bool collideRect(Rect *const other);
	virtual bool collideCircle(Circle *const other);
	virtual void draw(SDL_Renderer *renderer, bool fill);
};

class Rect : public Shape, public SDL_Rect{

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

		Rect copy();

		Shape asShape();

		bool operator==(Rect other);

		bool operator!=(Rect other);
};

struct Circle : public Shape{
	Vector2 pos;
	float radius;

	Circle();

	Circle(Vector2 _centre, float _radius);

	~Circle();

	bool collideCircle(Circle *const other);

	bool collideRect(Rect *const other);

	void draw(SDL_Renderer *renderer, bool fill);

	Circle copy();

	Shape asShape();

	bool operator==(Circle other);

	bool operator!=(Circle other);
};