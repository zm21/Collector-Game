#pragma once

int score = 0;
int score_add = 100;
float score_boost = 1;
int const SCORE_LVL = 300;
int life = 3;
int const SIZE_PLAYER_NAME = 255;
char player_name[SIZE_PLAYER_NAME];
short game_mode = 0;
int const MAX_NUMBER_OF_FALLING_SYMBOL = 10; //максимальна кількість падаючих символів
float score_boost_koef_default = 0.1; //коефіцієнт бусту під час серії правильно спійманих елементів під ряд
