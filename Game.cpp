#include "Game.h"

Game::Game(int width, int height, char *title, Uint32 flags, bool _threadedRender, int TPS, int FPS, float dt_threshold){

	running = true;

	deltaTime = 0;
	threadedRender = false;
	startedRenderThread = false;
	pauseRender = false;

	keyStates = 0;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	screen = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	screenRect = Rect(0, 0, width, height);

	clock = Clock(TPS);
	renderClock = Clock(FPS);
	DTThreshold = dt_threshold;

	threadedRender = _threadedRender;
}

void Game::update(){
		
}

void Game::render(){

}

void Game::handleKeyStates(const Uint8 *keyStates){

}

void Game::handleInput(){
	SDL_PollEvent(&WindowClosed);

	if (WindowClosed.type == SDL_QUIT){
		quit();
	}

	keyStates = SDL_GetKeyboardState(NULL);
	handleKeyStates(keyStates);
}

void Game::updateDisplay(){
	SDL_RenderPresent(renderer);
}

void Game::clearDisplay(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Game::threadRender(){
	while (running){
		if (pauseRender){
			continue;
		}

		renderClock.tick();
		frame();
	}
}

void Game::frame(){
	clearDisplay();
	render();
	updateDisplay();
}

std::thread Game::beginThreadedRendering(){
	startedRenderThread = true;

	return std::thread(&Game::threadRender, this);
}

void Game::run(){
	while (running){
		deltaTime = clock.tick();

		if (deltaTime > DTThreshold){
			/* A large deltaTime value indicates that the window was
				* being resized or dragged between now and the last
				* frame.This large dt value would, if left alone,
				* cause all sorts of problems for our game, such as
				* objects clipping through each other as their movement
				* is scaled by deltaTime. We thus skip this frame.
				*/

			continue;
		}

		pauseRender = true;
		handleInput();
		update();
		pauseRender = false;

		if (threadedRender){
			if (!startedRenderThread){
				renderThread = beginThreadedRendering();
			}

		}
		else{
			frame();
		}
	}
}

void Game::quit(){
	running = false;
	pauseRender = false;

	if (threadedRender){
		renderThread.join();
	}

	SDL_Quit();
}