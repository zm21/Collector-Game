#pragma once

enum Game_interface_coords   //координати ≥грового ≥нтерфейсу
{
	x_enter_player_name = 45, y_enter_player_name = 7,  //позиц≥€ вводу ≥мен≥ гравц€
	x_re_enter_player_name = 30, //позиц≥€ повторного вводу ≥мен≥ гравц€ у раз≥ не коректного н≥кнейму
	x_first_game_mode = 48, y_first_game_mode = 9, //позиц≥€ виводу вибору першого ≥грового режиму
	x_second_game_mode = 47, y_second_game_mode = 11, //позиц≥€ виводу вибору другого ≥грового режиму
	x_enter_the_selected_game_mode = 49, y_enter_the_selected_game_mode = 13, //позиц≥€ вводу вибраного режиму
	x_re_enter_the_selected_game_mode = 43, y_re_enter_the_selected_game_mode = 13, //позиц≥€ повторного вводу вибраного режиму у раз≥ не коректност≥ попередньо вибраного режиму 
	x_player_name = 33, y_player_name = 2, //позиц≥€ виводу гравц€
	x_life = 33, y_life = 4, //позиц≥€ виводу житт€
	x_score = 33, y_score = 6, //позиц≥€ виводу очк≥в
	x_bonus_task = 33, y_bonus_task = 8, // позиц≥€ виводу бонусного завданн€
	left_spawn = 1, right_spawn = 29, //л≥ва та права межа спавна дропу
	height_spawn = 1, //висота спавну
	left_border_move = 0, right_border_move = 30, //л≥ва та права межа руху коллектора
	x_game_over = 0, y_game_over = 7
};