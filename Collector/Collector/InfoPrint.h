#pragma once
#include <iostream>
#include "Player.h"
using namespace std;

enum Coord_show_best_players
{
	x_print_player = 40, y_print_player_default = 7,
	x_print_score= 56,
	y_interval = 2
};
enum Console_and_text_color
{
	console_color = 11,
	default_text_color = 0,
	logo_text_color = 1,
	error_text_color=4
};

void SetColor(Console_and_text_color text, Console_and_text_color background);


void gotoxy(int x, int y);
void Print_game_logo();
void Print_GAME_OVER();
void Print_best_player(Player* players, int &PLAYER_AMOUNT);
void Help();
void About_the_game();
bool Load_players_from_file(Player* & players, int & PLAYER_AMOUNT);