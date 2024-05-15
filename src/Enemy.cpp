#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>
#include "Enemy.h"

#define HEIGHT 720
#define WIDTH 720
#define SPEED 3

Enemy::Enemy(const char* texturesheet, int x, int y) :GameObject::GameObject(texturesheet, x, y)
{
	collider.h = 96;
	collider.w = 10;
	collider.x = xPos-5;
	collider.y = yPos;
}
Enemy::~Enemy()
{
	GameObject::~GameObject();
}
void Enemy::update(ball* b)
{
	GameObject::update();
	collider.x = xPos-5;
	collider.y = yPos;
	if (b->getyPos() <= yPos + destR.h/2 )
	{
		yPos -= SPEED;
	}
	if (b->getyPos() >= yPos + destR.h / 2)
	{
		yPos += SPEED;
	}
	if (yPos < 0)
	{
		yPos = 0;
	}
	if (yPos + destR.h > HEIGHT)
	{
		yPos = HEIGHT - destR.h;
	}
}
void Enemy::render()
{
	GameObject::render();
}
SDL_Rect& Enemy::getdestR()
{
	return collider;
}