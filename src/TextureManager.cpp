#include <iostream>
#include "Game.h"
#include "SDL_image.h"
#include <stdio.h>
#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	std::cout << "surface created"<<std::endl;
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	std::cout << "texture created"<< std::endl;
	SDL_FreeSurface(tempSurface);
	std::cout << "surface deleted"<< std::endl;
	return tex;
}
void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}