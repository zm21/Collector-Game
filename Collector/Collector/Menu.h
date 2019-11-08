#pragma once
#include <iostream>
#include "GlobalVariables.h"
enum Menu
{
	exit_game, start_play, show_best_players, help, about_the_game,
	x_enter_seletion = 45, y_enter_seletion = 17
};

void Menu(); //Стартове меню
void Help();
void About_the_game();


