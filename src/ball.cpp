#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "ball.h"
#include <iostream>
#include "Player.h"
#include <math.h>
#define PI 3.14159265358979323846
#define BALLSPEED 10.0
#define HEIGHT 720
#define WIDTH 720
#define FONT_SIZE 32

ball::ball(const char* texturesheet, int x, int y) :GameObject::GameObject(texturesheet,x,y)
{
	velX = BALLSPEED;
	velY = BALLSPEED;
	turn = true;
}
ball::~ball()
{
	GameObject::~GameObject();
}
void ball::update(Player* p,Enemy* e)
{
	GameObject::update();
	if (SDL_HasIntersection(&destR, &p->getdestR()))
	{
		double rel = (p->yPos + (p->getdestR().h / 2)) - (yPos + ( 32/ 2));
		double norm = rel / (p->getdestR().h / 2);
		double bounce = norm * (5 * PI / 12);
		velX = BALLSPEED * (float)cos(bounce);
		velY = BALLSPEED * (float)-sin(bounce);
	}
	if (SDL_HasIntersection(&destR, &e->getdestR()))
	{
		double rel = (e->yPos + (e->getdestR().h / 2)) - (yPos + (32 / 2));
		double norm = rel / (e->getdestR().h / 2);
		double bounce = norm * (5 * PI / 12);
		velX = -BALLSPEED * (float)cos(bounce);
		velY = BALLSPEED * (float)-sin(bounce);
	}
	if (xPos <= 30)
	{
		serve(p,e);
		s.enemy_score++;
	}
	if (xPos >= WIDTH - 30)
	{
		serve(p, e);
		s.player_score++;
	}
	if (xPos <= 0 || xPos >= WIDTH - (destR.w / 2))
	{
		velX = -velX;
	}
	if (yPos <= 0 || yPos >= HEIGHT - (destR.h / 2))
	{
		velY = -velY;
	}
	xPos += (int)velX;
	yPos += (int)velY;
	s.update();
}
void ball::serve(Player* p, Enemy* e)
{
	p->yPos = e->yPos = HEIGHT / 2 - 32;
	if (turn)
	{
		xPos = WIDTH / 2;
		velX = BALLSPEED / 2;
	}
	else {
		xPos = WIDTH / 2;
		velX = -BALLSPEED / 2;
	}
	velY = 0;
	yPos = HEIGHT / 2 - 16;
	turn = !turn;
}
void ball::render()
{
	GameObject::render();
	s.write(s.score, WIDTH / 2 + FONT_SIZE, FONT_SIZE * 3);
	s.write(s.highscore, WIDTH / 2 + 80, FONT_SIZE);
}
int ball::getxPos()
{
	return xPos;
}
int ball::getyPos()
{
	return yPos;
}