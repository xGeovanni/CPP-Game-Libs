#pragma once

#include "Time.h"
#include "Shapes.h"
#include <thread>

struct Game{
	SDL_Window *window;
	SDL_Surface *screen;
	SDL_Renderer *renderer;

	Rect screenRect;

	const Uint8 *keyStates;

	bool running;

	float deltaTime;
	float DTThreshold;
	Clock clock;

	std::thread renderThread;
	Clock renderClock;
	bool threadedRender;
	bool startedRenderThread;
	bool pauseRender;

	SDL_Event WindowClosed;

	Game(int width, int height, char *title, Uint32 flags, bool _threadedRender=false, int TPS=NULL, int FPS=NULL, float dt_threshold=0.2);

	virtual void update() = 0;

	virtual void render() = 0;

	virtual void handleKeyStates(const Uint8 *keyStates);

	void handleInput();

	void updateDisplay();

	void clearDisplay();

	void threadRender();

	void frame();

	std::thread beginThreadedRendering();

	void run();

	void quit();
};