#include "Menu.h"

void Menu() //Стартове меню
{
	system("color B0");
	int action_menu{};
	while (true)
	{
		system("cls");
		Print_game_logo();
		cout << endl << "\t\t\t\t\t\t  [" << start_play << "]Play" << endl;
		cout << endl << "\t\t\t\t\t    [" << show_best_players << "]Show best players" << endl;
		cout << endl << "\t\t\t\t\t\t  [" << help << "]Help" << endl;
		cout << endl << "\t\t\t\t\t     [" << about_the_game << "]About the game" << endl;
		cout << endl << "\t\t\t\t\t\t  [" << exit_game << "]Exit" << endl;
		gotoxy(x_enter_seletion, y_enter_seletion);
		cout << "Selected options:";
		cin >> action_menu;
		switch (action_menu)
		{
		case start_play:
		{
			Start_play();
			break;
		}
		case show_best_players:
		{
			Create_arr_players(players, PLAYER_AMOUNT);
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
			gotoxy(x_enter_seletion, y_enter_seletion);
			cout << "Error. Wrong action!" << endl;
			system("pause");
			break;
		}
		}
	}
}

