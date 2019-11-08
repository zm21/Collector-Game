#pragma once
#include "Drop.h"
#include "Collector.h"
#include "GamePrint.h"
#include <ctime>
#include <conio.h>

enum Game_mode
{
	math_mode = 1, //математичний режим
	verbal_mode = 2 //мовний режим
};
enum Score_inf
{
	score_add_default = 100, //дефолтне значення очків за спійманий символ
	score_boost_default = 1, //дефолтне значення бусту (стає при втраті серії з правильно спійманих елементів поспіль)
};
void Tracking_collerctor();
void Cathc_true_drop(Drop &falling_symbol);
void Cathc_false_drop(Drop &falling_symbol);
void No_cathc_true_drop(Drop &falling_symbol);
void No_cathc_false_drop(Drop &falling_symbol);