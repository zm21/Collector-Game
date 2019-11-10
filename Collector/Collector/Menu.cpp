#include "Menu.h"

void Menu() //Стартове меню
{
	system("color B0");
	int action_menu{};
	int const SIZE_OF_ACTION = 255;
	while (true)
	{
		system("cls");
		Print_game_logo();
		cout << endl << "\t\t\t\t\t\t  [" << start_play << "]Play" << endl;
		cout << endl << "\t\t\t\t\t    [" << show_best_players << "]Show best players" << endl;
		cout << endl << "\t\t\t\t\t\t  [" << help << "]Help" << endl;
		cout << endl << "\t\t\t\t\t     [" << about_the_game << "]About the game" << endl;
		cout << endl << "\t\t\t\t\t\t  [" << exit_game << "]Exit" << endl;
		gotoxy(x_enter_selection, y_enter_selection);
		cout << "Selected options:";
		char action_str[SIZE_OF_ACTION];
		cin.getline(action_str, SIZE_OF_ACTION);
		action_menu = (atoi(action_str) != 0) ? atoi(action_str) : wrong_action;
		switch (action_menu)
		{
		case start_play:
		{
			Start_play();
			break;
		}
		case show_best_players:
		{
			Clear_arr_players(players, PLAYER_AMOUNT);
			Load_players_from_file(players, PLAYER_AMOUNT);
			Sort_player(players, PLAYER_AMOUNT);
			Print_best_player(players, PLAYER_AMOUNT);
			break;
		}
		case help:
		{
			Help();
			break;
		}
		case about_the_game:
		{
			About_the_game();
			break;
		}
		case exit_game:
		{
			exit(0);
			break;
		}
		default:
		{
			SetColor(error_text_color, console_color);
			Clear_line(x_enter_selection, y_enter_selection);
			gotoxy(x_enter_selection, y_enter_selection);
			cout << "Error. Wrong action!" << endl;
			SetColor(default_text_color, console_color);
			system("pause");
			break;
		}
		}
	}
}


