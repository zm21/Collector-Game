#pragma once

enum Game_interface_coords   //���������� �������� ����������
{
	x_enter_player_name = 45, y_enter_player_name = 7,  //������� ����� ���� ������
	x_re_enter_player_name = 30, //������� ���������� ����� ���� ������ � ��� �� ���������� �������
	x_first_game_mode = 48, y_first_game_mode = 9, //������� ������ ������ ������� �������� ������
	x_second_game_mode = 47, y_second_game_mode = 11, //������� ������ ������ ������� �������� ������
	x_enter_the_selected_game_mode = 49, y_enter_the_selected_game_mode = 13, //������� ����� ��������� ������
	x_re_enter_the_selected_game_mode = 43, y_re_enter_the_selected_game_mode = 13, //������� ���������� ����� ��������� ������ � ��� �� ���������� ���������� ��������� ������ 
	x_player_name = 33, y_player_name = 2, //������� ������ ������
	x_life = 33, y_life = 4, //������� ������ �����
	x_score = 33, y_score = 6, //������� ������ ����
	x_bonus_task = 33, y_bonus_task = 8, // ������� ������ ��������� ��������
	left_spawn = 1, right_spawn = 29, //��� �� ����� ���� ������ �����
	height_spawn = 1, //������ ������
	left_border_move = 0, right_border_move = 30, //��� �� ����� ���� ���� ����������
	x_game_over = 0, y_game_over = 7
};