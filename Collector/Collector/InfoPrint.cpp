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
