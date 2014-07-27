#include "Vector.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
};

Vector2::Vector2(float X, float Y){
	x = X;
	y = Y;
}

float Vector2::toRadians(Vector2 v){
	return atan2(-v.x, v.y);
}

Vector2 Vector2::fromRadians(float rads){
	return Vector2(-cos(rads), sin(rads));
}

Vector2 Vector2::lerp(Vector2 a, Vector2 b, float t){
	return (a + (b - a) * t);
}

Vector2 Vector2::tween(Vector2 a, Vector2 b, Polynomial p, float t){
	float pt = p(t);
	return (a + (b - a) * pt);
}

float Vector2::magnitude(){
	return sqrt(magnitudeSquared());
}

float Vector2::magnitudeSquared(){
	return x*x + y*y;
}

Vector2 Vector2::normalised(){
	float m = magnitude();
	return Vector2(x / m, y / m);
}

void Vector2::normalise(){
	float m = magnitude();
	x /= m;
	y /= m;
}

Vector2 Vector2::angleTo(Vector2 other){
	float dx = x - other.x;
	float dy = y - other.y;

	return Vector2(dx, dy).normalised();
}

float Vector2::distanceTo(Vector2 other){
	return sqrt(distanceToSquared(other));
}

float Vector2::distanceToSquared(Vector2 other){
	float dx = x - other.x;
	float dy = y - other.y;

	return abs(dx*dx + dy*dy);
}

float Vector2::dot(Vector2 other){
	return (x * other.x + y * other.y);
}

float Vector2::cross(Vector2 other){
	return (x * other.y - y * other.x);
}

Vector2 Vector2::scaled(int m){
	if (x == 0 && y == 0){
		return Vector2(x, y);
	}

	float ratio = m / magnitude();

	return Vector2(x * ratio, y * ratio);
}
	
Vector2 Vector2::scaled(float m){
	if (x == 0 && y == 0){
		return Vector2(x, y);
	}

	float ratio = m / magnitude();

	return Vector2(x * ratio, y * ratio);
}

void Vector2::scale(int m){
	if (x == 0 && y == 0){
		return;
	}

	float ratio = m / magnitude();

	x *= ratio;
	y *= ratio;
}

void Vector2::scale(float m){
	if (x == 0 && y == 0){
		return;
	}

	float ratio = m / magnitude();

	x *= ratio;
	y *= ratio;
}

void Vector2::rotate(float rads){
	float s = sin(rads);
	float c = cos(rads);

	float X = x;

	x = X * c - y * s;
	y = X * s + y * c;
}

Vector2 Vector2::rotated(float rads){
	float s = sin(rads);
	float c = cos(rads);

	return Vector2(x * c - y * s, x * s + y * c);
}

//Beyond here lie the operator overloads.

void Vector2::operator=(Vector2 other){
	x = other.x;
	y = other.y;
}
	
bool Vector2::operator==(Vector2 other){
	return (x == other.x && y == other.y);
}

bool Vector2::operator!=(Vector2 other){
	return (x != other.x || y != other.y);
}
	
Vector2 Vector2::operator+(Vector2 other){
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(Vector2 other){
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(Vector2 other){
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator*(int mul){
	return Vector2(x * mul, y * mul);
}

Vector2 Vector2::operator*(float mul){
	return Vector2(x * mul, y * mul);
}

Vector2 Vector2::operator/(Vector2 other){
	return Vector2(x / other.x, y / other.y);
}

Vector2 Vector2::operator/(int div){
	return Vector2(x / div, y / div);
}

Vector2 Vector2::operator/(float div){
	return Vector2(x / div, y / div);
}

void Vector2::operator+=(Vector2 other){
	x += other.x;
	y += other.y;
}

void Vector2::operator-=(Vector2 other){
	x -= other.x;
	y -= other.y;
}

void Vector2::operator*=(Vector2 other){
	x *= other.x;
	y *= other.y;
}
	
void Vector2::operator*=(int mul){
	x *= mul;
	y *= mul;
}

void Vector2::operator*=(float mul){
	x *= mul;
	y *= mul;
}

void Vector2::operator/=(Vector2 other){
	x /= other.x;
	y /= other.y;
}

void Vector2::operator/=(int div){
	x /= div;
	y /= div;
}

void Vector2::operator/=(float div){
	x /= div;
	y /= div;
}