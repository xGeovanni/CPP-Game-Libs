#pragma once

#include "SDL.h"

class Clock{
	float desiredDT;
	float msDeltaTime;

	Uint32 currentTime;
	Uint32 lastTime;

	int delay;
	unsigned int lastDelay;

	void capTPS();

	public:
		unsigned int TPS; //Ticks per second cap.
		float deltaTime;

		Clock(int tps=NULL);

		float tick();
};