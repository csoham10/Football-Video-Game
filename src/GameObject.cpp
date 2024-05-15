#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
GameObject::GameObject(const char* texturesheet, int x, int y)
{
	
	objTexture = TextureManager::loadTexture(texturesheet);
	xPos = x;
	yPos = y;
	srcR.h = 32;
	srcR.w = 32;
	destR.h = srcR.h;
	destR.w = srcR.w;
}
GameObject::~GameObject()
{
}
void GameObject::update()
{


	
	srcR.x = 0;
	srcR.y = 0;

	destR.h = srcR.h;
	destR.w = srcR.w;
	destR.x = xPos;
	destR.y = yPos;
}
void GameObject::render()
{
	
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destR);
	
}
void GameObject::setSourceSize(int width, int height)
{
	srcR.w = width;
	srcR.h = height;
}