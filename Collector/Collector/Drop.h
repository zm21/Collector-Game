#pragma once
#include <Windows.h>
struct Drop
{
	char s;  //символ який падає
	int  x;  //позиція спавну предмету
	int y; //висота спавну предметів
};

void Ini_falling_symbol(Drop &falling_symbol);