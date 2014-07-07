#include "Shapes.h"

SDL_Point makePoint(int x, int y){
	SDL_Point p;
	p.x = x;
	p.y = y;
	return p;
}

void Rect::updateDrawValues(){
	x = roundf(pos.x);
	y = roundf(pos.y);
	w = roundf(size.x);
	h = roundf(size.y);
}

Vector2 pos;
Vector2 size;

Rect::Rect() {}

Rect::Rect(float _x, float _y, float _w, float _h){
	pos = Vector2(_x, _y);
	size = Vector2(_w, _h);

	updateDrawValues();
}

Rect::Rect(Vector2 _pos, Vector2 _size){
	pos = _pos;
	size = _size;

	updateDrawValues();
}

void Rect::draw(SDL_Renderer *renderer, bool fill){
	updateDrawValues();

	if (fill){
		SDL_RenderFillRect(renderer, this);
	}
	else{
		SDL_RenderDrawRect(renderer, this);
	}
}

bool Rect::collideRect(Rect *const other){
	if (pos.x > (other->pos.x + other->size.x) || (pos.x + size.x) < other->pos.x) return false;
	if (pos.y > (other->pos.y + other->size.y) || (pos.y + size.y) < other->pos.y) return false;
	return true;
}

bool Rect::collideCircle(Circle *const other){
	float distX = other->centre.x - (other->centre.x, pos.x, pos.x + size.x);
	float distY = other->centre.y - (other->centre.y, pos.y, pos.y + size.y);

	return distX * distX + distY * distY < other->radius * other->radius;
}

Circle::Circle() {}

Circle::Circle(Vector2 _centre, float _radius){
	centre = _centre;
	radius = _radius;
}

bool Circle::collideCircle(Circle *const other){
	float distSquared = (other->centre - centre).magnitudeSquared();
	return (radius * radius + other->radius * other->radius) < distSquared;
}

bool Circle::collideRect(Rect *const other){
	float distX = centre.x - (centre.x, other->pos.x, other->pos.x + other->size.x);
	float distY = centre.y - (centre.y, other->pos.y, other->pos.y + other->size.y);

	return distX * distX + distY * distY < radius * radius;
}

void Circle::draw(SDL_Renderer *renderer, bool fill){
	int x0 = roundf(centre.x);
	int y0 = roundf(centre.y);

	std::vector<SDL_Point> points;

	int x = radius;
	int y = 0;
	int radiusError = 1 - x;

	while (x >= y)
	{
		points.push_back(makePoint(x + x0, y + y0));
		points.push_back(makePoint(-x + x0, y + y0));
		points.push_back(makePoint(y + x0, x + y0));
		points.push_back(makePoint(-y + x0, x + y0));
		points.push_back(makePoint(x + x0, -y + y0));
		points.push_back(makePoint(-x + x0, -y + y0));
		points.push_back(makePoint(-y + x0, -x + y0));
		points.push_back(makePoint(y + x0, -x + y0));

		y++;
		if (radiusError < 0)
		{
			radiusError += 2 * y + 1;
		}
		else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}

	SDL_Point* ps = &points[0];

	if (fill){
		SDL_RenderDrawLines(renderer, ps, points.size());
	}

	else{
		SDL_RenderDrawPoints(renderer, ps, points.size());
	}

}