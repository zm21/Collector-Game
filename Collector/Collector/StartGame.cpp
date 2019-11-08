#include "StartGame.h"

void Start_play()
{
	system("cls");
	Print_game_logo();
	gotoxy(x_enter_player_name, y_enter_player_name);
	cout << "Enter player name:";
	cin >> player_name;
	while (strlen(player_name) > 10)
	{
		Clear_line(x_re_enter_player_name, y_enter_player_name);
		gotoxy(x_re_enter_player_name, y_enter_player_name);
		cout << "Maximum nickname length is 10 characters! Try again:";
		cin >> player_name;
	}
	gotoxy(x_first_game_mode, y_first_game_mode);
	cout << "[" << math_mode << "]Math mode";
	gotoxy(x_second_game_mode, y_second_game_mode);
	cout << "[" << verbal_mode << "]Verbal mode";
	gotoxy(x_enter_the_selected_game_mode, y_enter_the_selected_game_mode);
	cout << "Game mode:";
	cin >> game_mode;
	while (game_mode<math_mode || game_mode>verbal_mode)
	{
		Clear_line(x_re_enter_the_selected_game_mode, y_re_enter_the_selected_game_mode);
		gotoxy(x_re_enter_the_selected_game_mode, y_re_enter_the_selected_game_mode);
		cout << "Wrong game mode! Try again:";
		cin >> game_mode;
	}
	Print_play_zone();
	Print_interface();
	Tracking_collerctor();
	Sleep(3000);
	gotoxy(0, 26);
	system("pause");
}
