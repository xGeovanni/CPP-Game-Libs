#pragma once

#include <vector>
#include "Colour.h"
#include "Vector.h"

struct Player{
	SDL_Rect rect;
	Colour colour;

	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 force;
	Vector2 friction;

	float mass;
	float g;

	float mu;

	float fMax;

	std::vector<SDL_Rect> prevRects;
	float timeBetweenCaptureRect;
	float timeUntilCaptureRect;

	int numCapturedRects;

	Player();

	Player(float x, float y, float w, float h, Colour _colour, float _mass);

	void update(float deltaTime);

	void draw(SDL_Renderer *renderer);

	void handleKeyStates(const Uint8 *keyStates);
};