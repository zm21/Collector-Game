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

void gotoxy(int x, int y);
void Print_game_logo();
void Print_best_player(Player* players, int &PLAYER_AMOUNT);
void Help();
void About_the_game();
bool Load_players_from_file(Player* & players, int & PLAYER_AMOUNT);