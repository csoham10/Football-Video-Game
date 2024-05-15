#include "Scoreboard.h"
#include "Game.h"
#include <iostream>
#include "SDL_ttf.h"
#include <string>
#include <string.h>
#include <fstream>
#define FONT_SIZE 32

scoreboard::scoreboard()
{
	player_score = 0;
	enemy_score = 0;
	high_score = 0;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	score = std::to_string(player_score) + "  " + std::to_string(enemy_score);
	std::fstream file("highscore.txt", std::ios::in);
	file >> high_score;
	convert = std::to_string(high_score);
	highscore = "HIGHSCORE "+convert;
	std::cout << "highscore" << high_score << std::endl;
	font = TTF_OpenFont("JerseyM54-aLX9.ttf", FONT_SIZE);
	file.close();
}
scoreboard::~scoreboard()
{
	std::fstream file("highscore.txt", std::ios::out);
	std::cout << "New file for output" << std::endl;
	file << high_score << std::endl;
	TTF_CloseFont(font);
}
void scoreboard::write(std::string text, int x, int y)
{
	SDL_Surface* surface;
	SDL_Texture* texture;
	const char* t = text.c_str();
	surface = TTF_RenderText_Solid(font, t, color);
	texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	score_board.w = surface->w;
	score_board.h = surface->h;
	score_board.x = x - score_board.w;
	score_board.y = y - score_board.h;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(Game::renderer, texture, NULL, &score_board);
	SDL_DestroyTexture(texture);
}
void scoreboard::update()
{
	score = std::to_string(player_score) + "  " + std::to_string(enemy_score);
	if (player_score > high_score)
		high_score = player_score;
}