#include "Menu.h"
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;




enum control_the_game
{
	left = 'a', right = 'd'
};
enum Game_interface_coords   //координати ігрового інтерфейсу
{
	x_enter_player_name = 45, y_enter_player_name = 7,  //позиція вводу імені гравця
	x_re_enter_player_name = 30, //позиція повторного вводу імені гравця у разі не коректного нікнейму
	x_first_game_mode = 48, y_first_game_mode = 9, //позиція виводу вибору першого ігрового режиму
	x_second_game_mode = 47, y_second_game_mode = 11, //позиція виводу вибору другого ігрового режиму
	x_enter_the_selected_game_mode = 49, y_enter_the_selected_game_mode = 13, //позиція вводу вибраного режиму
	x_re_enter_the_selected_game_mode = 43, y_re_enter_the_selected_game_mode = 13, //позиція повторного вводу вибраного режиму у разі не коректності попередньо вибраного режиму 
	x_player_name = 33, y_player_name = 2, //позиція виводу гравця
	x_life = 33, y_life = 4, //позиція виводу життя
	x_score = 33, y_score = 6, //позиція виводу очків
	x_bonus_task = 33, y_bonus_task = 8, // позиція виводу бонусного завдання
	left_spawn = 1, right_spawn = 29, //ліва та права межа спавна дропу
	height_spawn = 1, //висота спавну
	left_border_move = 0, right_border_move = 30 //ліва та права межа руху коллектора
};
enum Game_mode
{
	math_mode = 1, //математичний режим
	verbal_mode = 2 //мовний режим
};
enum Score_inf
{
	score_add_default = 100, //дефолтне значення очків за спійманий символ
	score_boost_default = 1, //дефолтне значення бусту (стає при втраті серії з правильно спійманих елементів поспіль)
};

enum Math_mode_symbols_diapazone //Діапазони символів по ASCII для математичного режиму 
{
	min_first_diapazone_math = 40, max_first_diapazone_math = 43,  //перший математичний діапазон (множення, додавання, дужки)
	second_diapazone_math = 45,									   //другий математичний діапазон(входить тільки знак віднімання)
	min_third_diapazone_math = 47, max_third_diapazone_max = 57,   //третій математичний діапазон(знак ділення та цифри від 0 до 9)
	min_fourth_diapazone_math = 60, max_fourth_diapazone_math = 62 //четвертий математичний діапазон (знаки)
};
enum Verbal_mode_symbols_diapazone //Діапазони символів по ASCII для мовного режиму 
{
	first_diapazone_verbal = 33,  //перший мовний діапазон(знак оклику)
	second_diapazone_verbal = 44, //другий мовний діапазон(кома)
	third_diapazone_verbal = 46,  //третій мовний діапазон(крапка)
	fourth_diapazone_varbal = 63, //четвертий мовний діапазон(знак питання)
	min_fifth_diapazone_verbal = 65, max_fifth_diapazone_verbal = 90, //п'ятий мовний діапазон (великі літери)
	min_sixth_diapazone_verbal = 97, max_sixth_diapazone_verbal = 122 //шостий мовний діапазон (малі літери)
};








void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
void Clear_line(int const x, const int y);



void Print_game_logo();
void Start_play();
void Print_play_zone();
void Print_interface();

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
	int NUMBER_OF_FALLING_SYMBOL = 1; // 1 падаючий символ

	Drop* falling_symbols = (Drop*)malloc(sizeof(Drop) * NUMBER_OF_FALLING_SYMBOL);
	Ini_falling_symbol(falling_symbols[0]);
	falling_symbols[0].x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbols[0].y = height_spawn;
	bool add = false;
	gotoxy(collector.x, collector.y);
	cout << collector.s;
	int delay = 500; //затримка падіння
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
		if (_kbhit()) //перевіряємо чи щось нажато
		{
			gotoxy(collector.x, collector.y);
			cout << " ";
			switch (_getch()) //перевіряємо  чи потрібно рухатись
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
				//проста перевірка чи символ з математичного діапазону
				if ((falling_symbols[i].s >= min_first_diapazone_math && falling_symbols[i].s <= max_first_diapazone_math) || falling_symbols[i].s == second_diapazone_math || (falling_symbols[i].s >= min_third_diapazone_math && falling_symbols[i].s <= max_third_diapazone_max) || (falling_symbols[i].s >= min_fourth_diapazone_math && falling_symbols[i].s <= max_fourth_diapazone_math))
				{
					if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //перевірка чи користувач спіймав символ
					{
						Cathc_true_drop(falling_symbols[i]);
					}
					else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //перевірка чи користувач НЕ спіймав правильний символ 
					{
						No_cathc_true_drop(falling_symbols[i]);
					}
				}
				else if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //перевірка якщо користувач зловив не вірний символ
				{
					Cathc_false_drop(falling_symbols[i]);
				}
				else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //перевірка чи користувач НЕ спіймав не вірний символ
				{
					No_cathc_false_drop(falling_symbols[i]);
				}
				break;
			}
			case verbal_mode:
			{
				//проста перевірка чи символ з мовного діапазону
				if (falling_symbols[i].s == first_diapazone_verbal || falling_symbols[i].s == second_diapazone_verbal || falling_symbols[i].s == third_diapazone_verbal || falling_symbols[i].s == fourth_diapazone_varbal || (falling_symbols[i].s >= min_fifth_diapazone_verbal && falling_symbols[i].s <= max_fifth_diapazone_verbal) || (falling_symbols[i].s >= min_sixth_diapazone_verbal && falling_symbols[i].s <= max_sixth_diapazone_verbal))
				{
					if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //перевірка чи користувач спіймав символ
					{
						Cathc_true_drop(falling_symbols[i]);
					}
					else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //перевірка чи користувач НЕ спіймав правильний символ 
					{
						No_cathc_true_drop(falling_symbols[i]);
					}
				}
				else if (falling_symbols[i].x == collector.x && falling_symbols[i].y == collector.y) //перевірка якщо користувач зловив не вірний символ
				{
					Cathc_false_drop(falling_symbols[i]);
				}
				else if (falling_symbols[i].y == collector.y + 1 && falling_symbols[i].x != collector.x) //перевірка чи користувач НЕ спіймав не вірний символ
				{
					No_cathc_false_drop(falling_symbols[i]);
				}
				break;
			}
			}
		}
		if (score >= SCORE_LVL + *score_temp && NUMBER_OF_FALLING_SYMBOL != MAX_NUMBER_OF_FALLING_SYMBOL)
		{
			*score_temp = score * 1.5; //зберігаємо поточний результат очків
			start_add = clock();
			add = true;
			if (delay > 200)
			{
				delay -= 50;
			}
		}
		if (clock() > start_add + 2500 && add)
		{
			NUMBER_OF_FALLING_SYMBOL += 1; // змінюємо кількість падаючих символів 
			falling_symbols = (Drop*)realloc(falling_symbols, sizeof(Drop) * NUMBER_OF_FALLING_SYMBOL); //додаємо 1 елемент
			Ini_falling_symbol(falling_symbols[NUMBER_OF_FALLING_SYMBOL - 1]);
			falling_symbols[NUMBER_OF_FALLING_SYMBOL - 1].x = left_spawn + rand() % (right_spawn - left_spawn + 1);
			falling_symbols[NUMBER_OF_FALLING_SYMBOL - 1].y = height_spawn;
			add = false;
		}
	}
	delete score_temp; //звільняємо пам'ять від темпових очків
	free(falling_symbols); //звільняємо пам'ять від масиву структири з падаючими символами
}




void Cathc_true_drop(Drop &falling_symbol) //спіймано правильний символ
{
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << collector.s;
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	score_add *= score_boost;
	score += score_add;
	score_boost += score_boost_koef_default; //збільшуємо буст
	Print_interface();
	Ini_falling_symbol(falling_symbol); //рандомимо новий символ
}

void Cathc_false_drop(Drop &falling_symbol) //спіймано не правильний символ
{
	--life;
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << "U";
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	//повертаємо дефолтні значення бусту очків так, як серія спійманих поспіль символів перервана
	score_boost = score_boost_default;
	score_add = score_add_default;
	Print_interface();
	Ini_falling_symbol(falling_symbol); //рандомимо новий символ
}

void No_cathc_true_drop(Drop &falling_symbol) //не спіймано правильний символ
{
	--life;
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << "_";
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	//повертаємо дефолтні значення бусту очків так, як серія спійманих поспіль символів перервана
	score_boost = score_boost_default;
	score_add = score_add_default;
	Print_interface();
	Ini_falling_symbol(falling_symbol); //рандомимо новий символ
}

void No_cathc_false_drop(Drop &falling_symbol) //не спіймано НЕ правильний символ
{
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << "_";
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	Print_interface();
	Ini_falling_symbol(falling_symbol); //рандомимо новий символ
}

void Clear_line(int const x, const int y)
{
	gotoxy(x, y);
	for (int i = 0; i < 100; i++)
		cout << " ";
}