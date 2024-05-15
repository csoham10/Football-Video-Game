#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
class Player :public GameObject
{
public:
	SDL_Rect collider;
	Player(const char* texturesheet, int x, int y);
	~Player();
	void input();
	void update();
	void render();
	SDL_Rect& getdestR();
protected:

private:

};