#include "GamePrint.h"

void Print_play_zone()
{
	system("cls");
	int length_play_zone = 31; //довжина ігрового поля
	int height_play_zone = 25; //висота ігрового поля
	cout << " "; //ліва верхня грань ігрового поля
	for (int i = 0; i < length_play_zone - 2; i++)
	{
		cout << "_";//верхня межа
	}
	cout << " "; //права верхня грань ігрового поля
	cout << endl;
	for (int i = 0; i < height_play_zone; i++)
	{
		cout << "|";
		if (i == height_play_zone - 1)
			for (int i = 0; i < length_play_zone - 2; i++) //-2 тому, що 1 символ на ліву бокову грань "|" і ще 1 на праву
				cout << "_";
		else
			for (int j = 0; j < length_play_zone - 2; j++) //-2 тому, що 1 символ на ліву бокову грань "|" і ще 1 на праву
				cout << " ";
		cout << "|" << endl;
	}

	int length_interface_zone = 30; //довжина інтрефейс зони
	int height_interface_zone = 9; //висота інтрефейс зони

	int x = length_play_zone;
	int y = 0;
	gotoxy(x, y);
	for (int i = 0; i < length_interface_zone; i++)
	{
		cout << "_";
	}
	for (int i = 0; i < height_interface_zone; i++)
	{
		y++; //перехід на наступний рядок
		gotoxy(x, y);
		for (int j = 0; j < length_interface_zone; j++)
		{
			if (height_interface_zone - 1 == i)
				cout << "_";
			else
				cout << " ";
		}
		cout << "|" << endl;
	}
}

void Print_interface()
{
	gotoxy(x_player_name, y_player_name);
	cout << "Player name: " << player_name;
	gotoxy(x_life, y_life);
	cout << "Life: " << life;
	gotoxy(x_score, y_score);
	cout << "Score: " << score;
	gotoxy(x_bonus_task, y_bonus_task);
	cout << "Bonus task: " << score;
}