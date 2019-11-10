#include "GamePrint.h"

void Print_play_zone()
{
	system("cls");
	int length_play_zone = 31; //������� �������� ����
	int height_play_zone = 25; //������ �������� ����
	cout << " "; //��� ������ ����� �������� ����
	for (int i = 0; i < length_play_zone - 2; i++)
	{
		cout << "_";//������ ����
	}
	cout << " "; //����� ������ ����� �������� ����
	cout << endl;
	for (int i = 0; i < height_play_zone; i++)
	{
		cout << "|";
		if (i == height_play_zone - 1)
			for (int i = 0; i < length_play_zone - 2; i++) //-2 ����, �� 1 ������ �� ��� ������ ����� "|" � �� 1 �� �����
				cout << "_";
		else
			for (int j = 0; j < length_play_zone - 2; j++) //-2 ����, �� 1 ������ �� ��� ������ ����� "|" � �� 1 �� �����
				cout << " ";
		cout << "|" << endl;
	}

	int length_interface_zone = 30; //������� ��������� ����
	int height_interface_zone = 7; //������ ��������� ����

	int x = length_play_zone;
	int y = 0;
	gotoxy(x, y);
	for (int i = 0; i < length_interface_zone; i++)
	{
		cout << "_";
	}
	for (int i = 0; i < height_interface_zone; i++)
	{
		y++; //������� �� ��������� �����
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

void Print_interface(char* player_name, const int &life, const int &score)
{
	gotoxy(x_player_name, y_player_name);
	cout << "Player name: " << player_name;
	gotoxy(x_life, y_life);
	cout << "Life: " << life;
	gotoxy(x_score, y_score);
	cout << "Score: " << score;
}

void SetColor(Console_and_text_color text, Console_and_text_color background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void Clear_line(int const x, const int y)
{
	gotoxy(x, y);
	for (int i = 0; i < 100; i++)
		cout << " ";
}