#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>
class ball;
#include "ball.h"
class Enemy :public GameObject
{
public:
	SDL_Rect collider;
	Enemy(const char* texturesheet, int x, int y);
	~Enemy();
	void update(ball* b);
	void render();
	SDL_Rect& getdestR();
	
};