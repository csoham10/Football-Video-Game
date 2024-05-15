#pragma once
#include "Game.h"
class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* fileName);
	static void Draw(SDL_Texture*, SDL_Rect, SDL_Rect);
private:

protected:

};