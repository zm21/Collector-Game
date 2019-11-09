#pragma once
#include "InfoPrint.h"
#include "GameCoords.h"
#include "GlobalVariables.h"
#include <Windows.h>
void Print_play_zone();
void Print_interface(char* player_name, const int &life, const int &score);
void gotoxy(int x, int y);
void Clear_line(int const x, const int y);