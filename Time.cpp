#include "Time.h"

void Clock::capTPS(){
	if (!TPS){
		return;
	}

	delay = desiredDT - (deltaTime * 1000 - lastDelay);

	if (delay > 0){
		SDL_Delay(delay);
		lastDelay = delay;
	}
	else{
		lastDelay = 0;
	}
}

Clock::Clock(int tps){
	delay = 0;
	lastDelay = 0;

	deltaTime = 0;
	msDeltaTime = 0;

	TPS = tps;
	desiredDT = 1000.0 / TPS;

	currentTime = SDL_GetTicks();
	lastTime = SDL_GetTicks();
};

float Clock::tick(){
	capTPS();

	currentTime = SDL_GetTicks();

	msDeltaTime = (currentTime - lastTime);
	deltaTime = msDeltaTime / 1000.0;

	lastTime = SDL_GetTicks();

	return deltaTime;
};

void Clock::setTPS(int tps){
	TPS = tps;
	desiredDT = 1000 / tps;
}
