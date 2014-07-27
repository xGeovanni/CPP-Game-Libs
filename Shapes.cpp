#include "Shapes.h"

SDL_Point makePoint(int x, int y){
	SDL_Point p;
	p.x = x;
	p.y = y;
	return p;
}

bool Shape::collide(Shape *const other) {
	switch (other->type){
		case (ShapeType::rect) :
			return collideRect((Rect*)other);
		case (ShapeType::circle) :
			return collideCircle((Circle*)other);
		default:
			throw;
	}
}

bool Shape::collideCircle(Circle *const other) { 
	if (type == ShapeType::rect){
		return other->collideRect((Rect*) this);
	}
	else if (type == ShapeType::circle){
		return other->collideCircle((Circle*) this);
	}
}

bool Shape::collideRect(Rect *const other) { 
	if (type == ShapeType::rect){
		return other->collideRect((Rect*) this);
	}
	else if (type == ShapeType::circle){
		return other->collideCircle((Circle*) this);
	}
}

void Shape::draw(SDL_Renderer *renderer, bool fill) {
	if (type == ShapeType::rect){
		((Rect*)this)->draw(renderer, fill);
	}
	else if (type == ShapeType::circle){
		((Circle*)this)->draw(renderer, fill);
	}
}

void Rect::updateDrawValues(){
	x = roundf(pos.x);
	y = roundf(pos.y);
	w = roundf(size.x);
	h = roundf(size.y);
}

Rect::Rect() {
	type = ShapeType::rect;
}

Rect::Rect(float _x, float _y, float _w, float _h){
	type = ShapeType::rect;

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

Rect Rect::copy(){
	return Rect(pos, size);
}

bool Rect::collideRect(Rect *const other){
	return (pos.x < other->pos.x + other->size.x && pos.x + size.x > other->pos.x && pos.y < other->pos.y + other->size.y  && pos.y + size.y > other->pos.y);
}

bool Rect::collideCircle(Circle *const other){
	float distX = other->pos.x - (other->pos.x, pos.x, pos.x + size.x);
	float distY = other->pos.y - (other->pos.y, pos.y, pos.y + size.y);

	return distX * distX + distY * distY < other->radius * other->radius;
}

Shape Rect::asShape(){
	Shape s;
	s.pos = pos;
	s.type = ShapeType::rect;
	return s;
}

bool Rect::operator==(Rect other){
	return (pos == other.pos && size == other.size);
}

bool Rect::operator!=(Rect other){
	return (pos != other.pos || size != other.size);
}

Circle::Circle() {
	type = ShapeType::circle;
}

Circle::Circle(Vector2 _centre, float _radius){
	type = ShapeType::circle;

	pos = _centre;
	radius = _radius;
}

Circle::~Circle(){
}

Circle Circle::copy(){
	return Circle(pos, radius);
}

bool Circle::collideCircle(Circle *const other){
	float distSquared = (other->pos - pos).magnitudeSquared();
	return (radius * radius + other->radius * other->radius) < distSquared;
}

bool Circle::collideRect(Rect *const other){
	float distX = pos.x - (pos.x, other->pos.x, other->pos.x + other->size.x);
	float distY = pos.y - (pos.y, other->pos.y, other->pos.y + other->size.y);

	return distX * distX + distY * distY < radius * radius;
}

Shape Circle::asShape(){
	Shape s;
	s.pos = pos;
	s.type = ShapeType::circle;
	return s;
}

void Circle::draw(SDL_Renderer *renderer, bool fill){
	int x0 = roundf(pos.x);
	int y0 = roundf(pos.y);

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

bool Circle::operator==(Circle other){
	return (pos == other.pos && radius == other.radius);
}

bool Circle::operator!=(Circle other){
	return (pos != other.pos || radius != other.radius);
}