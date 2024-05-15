#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "Game.h"
#include "TextureManager.h"
#include "SDL_ttf.h"
#define HEIGHT 720
#define WIDTH 720
Game* game = NULL;
int main(int argc, char* argv[])
{
	const int FPS = 60;
	int frameDelay = 1000 / FPS;//Time taken for one frame
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->Init("Foosball", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
	game->firstone();
	while (game->running())
	{
		frameStart = SDL_GetTicks();//Start timer
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;//Total time taken for frame
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay-frameTime);//if time taken is less then delay so that it's 60FPS
		}
	}
	game->clean();
	
	return 0;
	
}