#include "Tileset.h"

Tileset::Tileset(int size_x, int size_y, int tileSize_x, int tileSize_y, int _gapSize){

	sizeX = size_x;
	sizeY = size_y;
	tileSizeX = tileSize_x;
	tileSizeY = tileSize_y;
	gapSize = _gapSize;

	for (int i=0; i < size_x; i++){
		tiles.push_back(std::vector<SDL_Rect>());
			
		for (int j=0; j < size_y; j++){
			SDL_Rect r;
			r.x = i * (tileSize_x + gapSize);
			r.y = j * (tileSize_y + gapSize);
			r.w = tileSize_x;
			r.h = tileSize_y;

			tiles[i].push_back(r);
		}
	}
}

SDL_Rect Tileset::multiTileRect(int x_start, int y_start, int width, int height){
	SDL_Rect r;
	r.x = (tileSizeX + gapSize) * x_start;
	r.y = (tileSizeY + gapSize) * y_start;
	r.w = (tileSizeX + gapSize) * width;
	r.h = (tileSizeY + gapSize) * height;

	return r;
}