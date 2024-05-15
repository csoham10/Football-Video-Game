#pragma once
#include "Game.h"
class GameObject {
public:
	int xPos;
	int yPos;
	GameObject(const char* texturesheet,int x, int y);
	~GameObject();

	virtual void update();
	virtual void render();
	void setSourceSize(int width, int height);
	
protected:
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};
