#pragma once

#include "Time.h"
#include "Shapes.h"
#include "Colour.h"
#include <thread>
#include <iostream>

struct Game{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_DisplayMode* displayMode;

	Rect screenRect;

	const Uint8 *keyStates;

	bool running;

	float deltaTime;
	float DTThreshold;
	Clock clock;

	enum GameStates{
		intro,
		menu,
		game,
		editor,
	};

	GameStates state;

	std::thread renderThread;
	Clock renderClock;
	bool threadedRender;
	bool startedRenderThread;
	bool pauseRender;

	Colour fillColour; 

	SDL_Event e;

	Game(int width, int height, char *title, Uint32 flags, bool _threadedRender = false, int TPS = NULL, int FPS = NULL, float dt_threshold = 0.2);

	~Game();

	virtual void update();

	virtual void render();

	virtual void handleEvents(const Uint8* keyStates, SDL_Event* e);

	void handleInput();

	void updateDisplay();

	void clearDisplay();

	void threadRender();

	void frame();

	std::thread beginThreadedRendering();

	void run();

	void quit();
};