#include "Menu.h"
#include <conio.h>
#include <ctime>
using namespace std;





enum Game_mode
{
	math_mode = 1, //������������ �����
	verbal_mode = 2 //������ �����
};
enum Score_inf
{
	score_add_default = 100, //�������� �������� ���� �� �������� ������
	score_boost_default = 1, //�������� �������� ����� (��� ��� ����� ��� � ��������� �������� �������� ������)
};


void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
void Clear_line(int const x, const int y);


void Start_play();
void Print_game_logo();


void Tracking_collerctor();

void Cathc_true_drop(Drop &falling_symbol);
void Cathc_false_drop(Drop &falling_symbol);
void No_cathc_true_drop(Drop &falling_symbol);
void No_cathc_false_drop(Drop &falling_symbol);


int main()
{

	Menu();
	system("pause");
}








void Tracking_collerctor()
{
	//fix cursor
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);


	int *score_temp = new int;
	*score_temp = 0;
	int NUMBER_OF_FALLING_SYMBOL = 1; // 1 �������� ������

	Drop* falling_symbols = (Drop*)malloc(sizeof(Drop) * NUMBER_OF_FALLING_SYMBOL);
	Ini_falling_symbol(falling_symbols[0]);
	falling_symbols[0].x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbols[0].y = height_spawn;
	bool add = false;
	gotoxy(collector.x, collector.y);
	cout << collector.s;
	int delay = 500; //�������� ������
	clock_t start = clock();
	clock_t start_add{};
	life = 0;
	score = 0;
	while (life > 0)
	{
		if (clock() >= start + delay)
		{
			for (int i = 0; i < NUMBER_OF_FALLING_SYMBOL; i++)
			{
				gotoxy(falling_symbols[i].x, falling_symbols[i].y);
				cout << ' ';
				start = clock();
				++falling_symbols[i].y;
				gotoxy(falling_symbols[i].x, falling_symbols[i].y);
				cout << falling_symbols[i].s;
			}
		}
		if (_kbhit()) //���������� �� ���� ������
		{
			gotoxy(collector.x, collector.y);
			cout << " ";
			switch (_getch()) //����������  �� ������� ��������
			{
			case move_left:
			{
				if (collector.x - 1 != left_border_move)
				{
					collector.x--;
				}
				break;
			}
			case move_right:
			{
				if (collector.x + 1 != right_border_move)
				{
					collector.x++;
				}
				break;
			}
			}
			gotoxy(collector.x, collector.y);
			cout << collector.s;
		}
		for (int i = 0; i < NUMBER_OF_FALLING_SYMBOL; i++)
		{
			switch (game_mode)
			{
			case math_mode:
			{
				//������ �������� �� ������ � ������������� ��������
				if ((falling_symbols[i].s >= min_first_diapazone_math && falling_symbols[i].s <= max_first_diapazone_math) || falling_symbols[i].s == second_diapazone_math || (falling_symbols[i].s >= min_third_diapazone_math && falling_symbols[i].s <= max_third_diapazone_max) || (falling_symbols[i].s >= min_fourth_diapazone_math && falling_symbols[i].s <= max_fourth_diapazone_math))
				{
					if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //�������� �� ���������� ������ ������
					{
						Cathc_true_drop(falling_symbols[i]);
					}
					else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //�������� �� ���������� �� ������ ���������� ������ 
					{
						No_cathc_true_drop(falling_symbols[i]);
					}
				}
				else if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //�������� ���� ���������� ������ �� ����� ������
				{
					Cathc_false_drop(falling_symbols[i]);
				}
				else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //�������� �� ���������� �� ������ �� ����� ������
				{
					No_cathc_false_drop(falling_symbols[i]);
				}
				break;
			}
			case verbal_mode:
			{
				//������ �������� �� ������ � ������� ��������
				if (falling_symbols[i].s == first_diapazone_verbal || falling_symbols[i].s == second_diapazone_verbal || falling_symbols[i].s == third_diapazone_verbal || falling_symbols[i].s == fourth_diapazone_varbal || (falling_symbols[i].s >= min_fifth_diapazone_verbal && falling_symbols[i].s <= max_fifth_diapazone_verbal) || (falling_symbols[i].s >= min_sixth_diapazone_verbal && falling_symbols[i].s <= max_sixth_diapazone_verbal))
				{
					if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //�������� �� ���������� ������ ������
					{
						Cathc_true_drop(falling_symbols[i]);
					}
					else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //�������� �� ���������� �� ������ ���������� ������ 
					{
						No_cathc_true_drop(falling_symbols[i]);
					}
				}
				else if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //�������� ���� ���������� ������ �� ����� ������
				{
					Cathc_false_drop(falling_symbols[i]);
				}
				else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //�������� �� ���������� �� ������ �� ����� ������
				{
					No_cathc_false_drop(falling_symbols[i]);
				}
				break;
			}
			}
		}
		if (score >= SCORE_LVL + *score_temp && NUMBER_OF_FALLING_SYMBOL != MAX_NUMBER_OF_FALLING_SYMBOL)
		{
			*score_temp = score * 1.5; //�������� �������� ��������� ����
			start_add = clock();
			add = true;
			if (delay > 200)
			{
				delay -= 50;
			}
		}
		if (clock() > start_add + 2500 && add)
		{
			NUMBER_OF_FALLING_SYMBOL += 1; // ������� ������� �������� ������� 
			falling_symbols = (Drop*)realloc(falling_symbols, sizeof(Drop) * NUMBER_OF_FALLING_SYMBOL); //������ 1 �������
			Ini_falling_symbol(falling_symbols[NUMBER_OF_FALLING_SYMBOL - 1]);
			falling_symbols[NUMBER_OF_FALLING_SYMBOL - 1].x = left_spawn + rand() % (right_spawn - left_spawn + 1);
			falling_symbols[NUMBER_OF_FALLING_SYMBOL - 1].y = height_spawn;
			add = false;
		}
	}
	delete score_temp; //��������� ���'��� �� �������� ����
	free(falling_symbols); //��������� ���'��� �� ������ ��������� � ��������� ���������
}




void Cathc_true_drop(Drop &falling_symbol) //������� ���������� ������
{
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << collector.s;
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	score_add *= score_boost;
	score += score_add;
	score_boost += score_boost_koef_default; //�������� ����
	Print_interface();
	Ini_falling_symbol(falling_symbol); //��������� ����� ������
}

void Cathc_false_drop(Drop &falling_symbol) //������� �� ���������� ������
{
	--life;
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << "U";
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	//��������� ������� �������� ����� ���� ���, �� ���� �������� ������ ������� ���������
	score_boost = score_boost_default;
	score_add = score_add_default;
	Print_interface();
	Ini_falling_symbol(falling_symbol); //��������� ����� ������
}

void No_cathc_true_drop(Drop &falling_symbol) //�� ������� ���������� ������
{
	--life;
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << "_";
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	//��������� ������� �������� ����� ���� ���, �� ���� �������� ������ ������� ���������
	score_boost = score_boost_default;
	score_add = score_add_default;
	Print_interface();
	Ini_falling_symbol(falling_symbol); //��������� ����� ������
}

void No_cathc_false_drop(Drop &falling_symbol) //�� ������� �� ���������� ������
{
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << "_";
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	Print_interface();
	Ini_falling_symbol(falling_symbol); //��������� ����� ������
}

