#include "InfoPrint.h"

void Help()
{
	system("cls");
	Print_game_logo();
	cout << endl << "\t\t\t\t\t Hi, welcome to COLLECTOR" << endl;
	system("pause");
}

void About_the_game()
{
	system("cls");
	Print_game_logo();
	cout << endl << "\t\t\t\t\t Developer Mikola Zaiets" << endl;
	system("pause");
}

void Print_game_logo()
{
	cout << "\t\t  _____    _____   __      __      _____    _____   ________   _____   _____	" << endl;
	cout << "\t\t |   __|  |  _  | |  |    |  |    |   __|  |   __| |__    __| |  _  | |  _  |" << endl;
	cout << "\t\t |  |     | | | | |  |    |  |    |  |__   |  |       |  |    | | | | | |_| |	" << endl;
	cout << "\t\t |  |     | | | | |  |    |  |    |   __|  |  |       |  |    | | | | |  _  |	" << endl;
	cout << "\t\t |  |__   | |_| | |  |__  |  |__  |  |__   |  |__     |  |    | |_| | | | \\ \\	" << endl;
	cout << "\t\t |______| |_____| |_____| |_____| |_____|  |_____|    |__|    |_____| |_|  \\_\\ " << endl;
}

void Print_GAME_OVER()
{
	cout << "	 ________    ______    ___    ___   _____     " << endl;
	cout << "	|   _____|  /  __  \\  |   \\  /   | |   __|    " << endl;
	cout << "	|  |  ___  |  |__|  | |    \\/    | |  |__   " << endl;
	cout << "	|  | |__ | |   __   | |  |\\  /|  | |   __|	 " << endl;
	cout << "	|  |___| | |  |  |  | |  | \\/ |  | |  |__	 " << endl;
	cout << "	|________| |__|  |__| |__|    |__| |_____|	 " << endl;
	cout << "	 _______  ___      ___  _____   _______		 " << endl;
	cout << "	|   _   | \\  \\    /  / |   __| |   _   |		 " << endl;
	cout << "	|  | |  |  \\  \\  /  /  |  |__  |  |_|  |	 " << endl;
	cout << "	|  | |  |   \\  \\/  /   |   __| |   _   |	 " << endl;
	cout << "	|  |_|  |    \\    /    |  |__  |  | \\  \\	 " << endl;
	cout << "	|_______|     \\__/     |_____| |__|  \\__\\		 " << endl;
	cout << "|                                                " << endl;
}
void Print_best_player(Player* players, int &PLAYER_AMOUNT)
{
	system("cls");
	Print_game_logo();\
	
	if (PLAYER_AMOUNT != 0)
	{
		int y_print_player = y_print_player_default;
		gotoxy(x_print_player, y_print_player);
		cout << "Player name\tBest score" << endl;
		y_print_player += y_interval;
		if (PLAYER_AMOUNT > 10)
		{
			for (int i = 0; i < 10; i++)
			{
				gotoxy(x_print_player, y_print_player);
				cout << "[" << i + 1 << "]" << players[i].player_name;
				gotoxy(x_print_score, y_print_player);
				cout << players[i].best_score << endl;
				y_print_player += y_interval;
			}
		}
		else if (PLAYER_AMOUNT > 0)
		{
			for (int i = 0; i < PLAYER_AMOUNT; i++)
			{
				gotoxy(x_print_player, y_print_player);
				cout << "[" << i + 1 << "]" << players[i].player_name;
				gotoxy(x_print_score, y_print_player);
				cout << players[i].best_score << endl;
				y_print_player += y_interval;
			}
		}
	}
	else
	{
		cout << endl<<"\t\t\t\t\t\t No players!" << endl;
	}
	
	system("pause");
}
