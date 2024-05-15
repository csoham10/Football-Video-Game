#pragma once
#include "Game.h"
#include <vector>
class Map {
public:
	Map();
	~Map();
	void LoadMap(std::vector<std::vector<int>> arr);
	void DrawMap();
private:
	SDL_Rect src, dest;
	SDL_Texture* grass;
	//SDL_Texture* midline;
	SDL_Texture* grass_1;
	SDL_Texture* puddle;
	std::vector<std::vector<int>> map;
};
