#include "Player.h"

Player::Player() {}

Player::Player(float x, float y, float w, float h, Colour _colour, float _mass){

	g = 40;
	mu = .8;
	timeBetweenCaptureRect = 0.001;
	timeUntilCaptureRect = 0;
	numCapturedRects = 800;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	position.x = x;
	position.y = y;

	colour = _colour;
	mass = _mass;

	fMax = mu * mass * g;
}

void Player::update(float deltaTime){
	if (!(velocity.x == 0 && velocity.y == 0)){
		friction = velocity.normalised() * fMax;
	}
	else{
		friction.x = 0;
		friction.y = 0;
	}

	acceleration = (force - friction) / mass;
	velocity += acceleration * deltaTime;
	position += velocity * deltaTime;

	timeUntilCaptureRect -= deltaTime;
	if (timeUntilCaptureRect <= 0){

		int num = 1 + roundf(abs(timeUntilCaptureRect) / timeBetweenCaptureRect);

		SDL_Rect r;
		r.x = rect.x;
		r.y = rect.y;
		r.w = rect.w;
		r.h = rect.h;

		for (int i = 0; i < num; i++){
			prevRects.push_back(r);
		}

		timeUntilCaptureRect = timeBetweenCaptureRect;
	}
}

void Player::draw(SDL_Renderer *renderer){
	int max;

	if (prevRects.size() < numCapturedRects){
		max = prevRects.size();
	}
	else{
		max = numCapturedRects;
	}

	for (int i = max; i > 0; i--){
		SDL_SetRenderDrawColor(renderer, floor(colour.r - colour.r * i / max), floor(colour.g - colour.g * i / max), floor(colour.b - colour.b * i / max), floor(colour.a * i / max));
		SDL_RenderFillRect(renderer, &prevRects[prevRects.size() - i]);
	}

	rect.x = roundf(position.x);
	rect.y = roundf(position.y);
}

void Player::handleKeyStates(const Uint8 *keyStates){
	if (keyStates[SDL_SCANCODE_UP] || keyStates[SDL_SCANCODE_W]){
		force.y = -1.0;
	}
	else if (keyStates[SDL_SCANCODE_DOWN] || keyStates[SDL_SCANCODE_S]){
		force.y = 1.0;
	}
	else{
		force.y = 0;
	}

	if (keyStates[SDL_SCANCODE_LEFT] || keyStates[SDL_SCANCODE_A]){
		force.x = -1.0;
	}
	else if (keyStates[SDL_SCANCODE_RIGHT] || keyStates[SDL_SCANCODE_D]){
		force.x = 1.0;
	}
	else{
		force.x = 0;
	}

	if (!(force.x == 0 && force.y == 0)){
		force.normalise();
	}
}