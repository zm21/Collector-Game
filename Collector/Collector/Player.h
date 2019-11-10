#pragma once
#include "GlobalVariables.h"
struct Player
{
	char player_name [SIZE_PLAYER_NAME];
	int best_score;
};
namespace
{
	int PLAYER_AMOUNT = 0;
	Player *players = new Player;
}