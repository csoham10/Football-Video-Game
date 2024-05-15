#pragma once
#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

class Game
{
public:
	Game();
	
	~Game();
	
	void Init(char const* title, int posx, int posy, int width, int height,bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	static SDL_Renderer* renderer;
	void firstone();
private:
	int counter;
	bool isRunning;
	SDL_Window* window = NULL;
	
protected:
};