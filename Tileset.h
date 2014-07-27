#pragma once

#include "SDL.h"
#include <vector>

struct Tileset{
	std::vector<std::vector<SDL_Rect> > tiles;

	int sizeX;
	int sizeY;
	int tileSizeX;
	int tileSizeY;
	int gapSize;

	Tileset(int size_x, int size_y, int tileSize_x, int tileSize_y, int _gapSize);

	SDL_Rect multiTileRect(int x_start, int y_start, int width, int height);
};