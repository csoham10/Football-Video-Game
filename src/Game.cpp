#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ball.h"
#include "Player.h"
#include "Enemy.h"
#include <exception>
#define HEIGHT 720
#define WIDTH 720
Map* map;
Player* p = nullptr;
ball* b = nullptr;
Enemy* e = nullptr;
SDL_Renderer* Game::renderer = nullptr;
Game::Game()
{
	isRunning = true;
	counter = 0;
}
Game::~Game()
{

}
void Game::Init(char const* title, int posx, int posy, int width, int height,bool fullscreen)
{
	int flag = 0;
	if (fullscreen)
		flag = SDL_WINDOW_FULLSCREEN;
	try {
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "SDL initialized" << std::endl;
			window = SDL_CreateWindow(title, posx, posy, width, height, flag);
			if (window)
				std::cout << "Window created" << std::endl;
			else
				throw(2);
			Game::renderer = SDL_CreateRenderer(window, -1, 0);
			if (Game::renderer)
			{
				SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
				std::cout << "Renderer created" << std::endl;
			}
			else
				throw(3);
			if (TTF_Init() == 0)
				std::cout << "Font Initialized" << std::endl;
			else
				throw(4);
			isRunning = true;

			map = new Map();
			b = new ball("football.png", WIDTH / 2, HEIGHT / 2);
			p = new Player("player1.png", 6, 360);
			p->setSourceSize(96, 96);
			e = new Enemy("player2.png", WIDTH - 96, HEIGHT / 2);
			e->setSourceSize(96, 96);




		}
		else
		{
			isRunning = false;
			throw(1);
		}

	}
	catch (int i)
	{
		if (i == 1)
			std::cout << "Failed to Initialize SDL : " << SDL_GetError() << std::endl;
		else if (i == 2)
			std::cout << "Window not created : " << SDL_GetError() << std::endl;
		else if (i == 3)
			std::cout << "Renderer not created : " << SDL_GetError() << std::endl;
		else if (i == 4)
			std::cout << "Fonts not Initialized : " << TTF_GetError() << std::endl;

		exit(1);
	}
	
	
}
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}
	
}
void Game::update()
{
	
	b->update(p,e);
	p->update();
	p->input();
	e->update(b);
	
}
void Game::render()
{
	SDL_RenderClear(Game::renderer);
	map->DrawMap();
	b->render();
	p->render();
	e->render();
	SDL_RenderPresent(Game::renderer);
}
void Game::clean()
{
	delete b;
	b = nullptr;
	delete p;
	p = nullptr;
	delete e;
	e = nullptr;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
	
}
bool Game::running()
{
	return isRunning;
}
void Game::firstone()
{
	b->serve(p,e);
}