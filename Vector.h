#pragma once

#include "Maths.h"

struct Vector2{
	float x;
	float y;

	Vector2();

	Vector2(float X, float Y);

	static float toRadians(Vector2 v);

	static Vector2 fromRadians(float rads);

	static Vector2 lerp(Vector2 a, Vector2 b, float t);

	static Vector2 tween(Vector2 a, Vector2 b, Polynomial p, float t);

	float magnitude();

	float magnitudeSquared();

	Vector2 normalised();

	void normalise();

	Vector2 angleTo(Vector2 other);

	float distanceTo(Vector2 other);

	float distanceToSquared(Vector2 other);

	float dot(Vector2 other);

	float cross(Vector2 other);

	Vector2 scaled(int m);

	Vector2 scaled(float m);

	void scale(int m);

	void scale(float m);

	void rotate(float rads);

	Vector2 rotated(float rads);

	//Beyond here lie the operator overloads.

	void operator=(Vector2 other);

	bool operator==(Vector2 other);

	bool operator!=(Vector2 other);

	Vector2 operator+(Vector2 other);

	Vector2 operator-(Vector2 other);

	Vector2 operator*(Vector2 other);

	Vector2 operator*(int mul);

	Vector2 operator*(float mul);

	Vector2 operator/(Vector2 other);

	Vector2 operator/(int div);

	Vector2 operator/(float div);

	void operator+=(Vector2 other);

	void operator-=(Vector2 other);

	void operator*=(Vector2 other);

	void operator*=(int mul);

	void operator*=(float mul);

	void operator/=(Vector2 other);

	void operator/=(int div);

	void operator/=(float div);
};

