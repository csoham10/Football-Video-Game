#pragma once
#include "SDL_ttf.h"
#include <iostream>
#include "Game.h"
class scoreboard
{
public:
	TTF_Font *font;
	SDL_Color color;
	std::string score;
	std::string highscore;
	std::string convert;
	scoreboard();
	~scoreboard();
	int player_score, enemy_score;
	int high_score;
	void write(std::string text, int x, int y);
	void update();
	SDL_Rect score_board;
protected:
private:

};
