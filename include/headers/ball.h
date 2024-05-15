#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>
#include "Player.h"
#include "Scoreboard.h"
#include "SDL_ttf.h"
class Enemy;
#include "Enemy.h"
class ball:public GameObject
{
public:
	ball(const char* texturesheet, int x, int y);
	~ball();
	void serve(Player* p,Enemy* e);
	void update(Player* p,Enemy* e);
	void render();
	int getyPos();
	int getxPos();
	
protected:
	scoreboard s;
	bool turn;
	double velX;
	double velY;
private:

};