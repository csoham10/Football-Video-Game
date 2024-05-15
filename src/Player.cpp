#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#define HEIGHT 720
#define WIDTH 720
#define SPEED 6

Player::Player(const char* texturesheet, int x, int y):GameObject::GameObject(texturesheet,x,y)
{
	collider.h = 96;
	collider.w = 10;
	collider.x = xPos+50;
	collider.y = yPos;
}
Player::~Player()
{
	GameObject::~GameObject();
}
void Player::update()
{
	GameObject::update();
	collider.x = xPos+40;
	collider.y = yPos;
	if (yPos <= 0)
		yPos = 0;
	if (yPos + destR.h >= HEIGHT)
		yPos = HEIGHT - destR.h;
}
void Player::render()
{
	GameObject::render();

}
void Player::input()
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) yPos -= SPEED;
	if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) yPos += SPEED;

}
SDL_Rect& Player::getdestR()
{
	return collider;
}