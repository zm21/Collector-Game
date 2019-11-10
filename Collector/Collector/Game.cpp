#include "Game.h"


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
	life = life_default;
	score = NULL;
	Print_interface(player_name, life, score);
	Tracking_collerctor();
	Sleep(3000);
	gotoxy(0, 26);
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
	int NUMBER_OF_FALLING_SYMBOL = 1; // 1 падаючий символ

	Drop* falling_symbols = (Drop*)malloc(sizeof(Drop) * NUMBER_OF_FALLING_SYMBOL);
	Ini_falling_symbol(falling_symbols[0]);
	falling_symbols[0].x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbols[0].y = height_spawn;
	bool add = false;
	gotoxy(collector.x, collector.y);
	cout << collector.s;
	int delay = 200; //затримка падіння
	clock_t start = clock();
	clock_t start_add{};
	life = life_default;
	score = NULL;
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
			case '`':
			{
				score += 100;
				Print_interface(player_name, life, score);
				break;
			}
			case 'l':
			{
				life -= 3;
				Print_interface(player_name, life, score);
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
	gotoxy(x_game_over, y_game_over);
	Print_GAME_OVER();
	Load_players_from_file(players, PLAYER_AMOUNT);
	Add_player(player_name, score, players, PLAYER_AMOUNT);
	Create_arr_players(players, PLAYER_AMOUNT);
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
	Print_interface(player_name, life, score);
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
	Print_interface(player_name, life, score);
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
	Print_interface(player_name, life, score);
	Ini_falling_symbol(falling_symbol); //рандомимо новий символ
}

void No_cathc_false_drop(Drop &falling_symbol) //не спіймано НЕ правильний символ
{
	gotoxy(falling_symbol.x, falling_symbol.y);
	cout << "_";
	falling_symbol.x = left_spawn + rand() % (right_spawn - left_spawn + 1);
	falling_symbol.y = height_spawn;
	Print_interface(player_name, life, score);
	Ini_falling_symbol(falling_symbol); //рандомимо новий символ
}

