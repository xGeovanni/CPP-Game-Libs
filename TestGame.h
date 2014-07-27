#pragma once

#include "Player.h"
#include "Game.h"

struct TestGame : Game{
	Player player;

	float fps_average;
	float nFrames;

	TestGame();

	void update();

	void render();

	void handleKeyStates(const Uint8 *keyStates);
};