#pragma once
#include <fstream>
#include "Player.h"
using namespace std;

bool Load_player_amount(int&PLAYER_AMOUNT);
bool Save_players_to_file(Player* players, const int &PLAYER_AMOUNT);
bool Load_players_from_file(Player* & players, int & PLAYER_AMOUNT);
void Sort_player(Player*&players, const int &PLAYER_AMOUNT);
void Add_player(char* player_name, int score, Player*&players, int &PLAYER_AMOUNT);
void Create_arr_players(Player*&players, int &PLAYER_AMOUNT);