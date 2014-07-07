#include "TestGame.h"
#include <iostream>

TestGame::TestGame() : Game(800, 600, "Star", 0, true, 1000, 240) {
	player = Player(320, 240, 20, 20, Colour(255, 255, 255), .011);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	float fps_average = 0;
	float nFrames = 0;

	v = Vector2(400, 400);
	for (int i = 0; i < 30; i++){
		c[i] = Circle(v, 300);
	}
}

void TestGame::update(){
	player.update(deltaTime);

	if (nFrames == 0){
		fps_average = floor(1 / deltaTime);
		nFrames++;
	}
	else{
		fps_average = (fps_average * nFrames + floor(1 / deltaTime)) / nFrames++;
	}
}

void TestGame::render(){
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	player.draw(renderer);

	/*SDL_Rect r;
	r.w = 20;
	r.h = 20;

	for (int i = 0; i < 6400; i++){
	r.x = ((std::rand() % 800));
	r.y = ((std::rand() % 600));

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, rand() % 256);
	SDL_RenderFillRect(renderer, &r);
	}*/

}

void TestGame::handleKeyStates(const Uint8 *keyStates){
	player.handleKeyStates(keyStates);

	if (keyStates[SDL_SCANCODE_RETURN]){
		std::cout << fps_average << "\n";
	}
}