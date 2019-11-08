#include "Drop.h"

void Ini_falling_symbol(Drop &falling_symbol)
{
	int action = 1 + rand() % (2 - 1 + 1);
	//рондом символа за ASCII TABLE
	switch (action)
	{
	case 1: //математичний рандом
	{
		short math_random = 1 + rand() % (4 - 1 + 1); //рандом діапазону 
		switch (math_random)
		{
		case 1: //перший математичний діапазон (множення, додавання, дужки)
		{
			falling_symbol.s = min_first_diapazone_math + rand() % (max_first_diapazone_math - min_first_diapazone_math + 1);
			break;
		}
		case 2: //другий математичний діапазон(входить тільки знак віднімання)
		{
			falling_symbol.s = second_diapazone_math;
			break;
		}
		case 3: //третій математичний діапазон(знак ділення та цифри від 0 до 9)
		{
			falling_symbol.s = min_third_diapazone_math + rand() % (max_third_diapazone_max - min_third_diapazone_math + 1);
			break;
		}
		case 4: //четвертий математичний діапазон (знаки)
		{
			falling_symbol.s = min_fourth_diapazone_math + rand() % (max_fourth_diapazone_math - min_fourth_diapazone_math + 1);
			break;
		}
		}
		break;
	}
	case 2: //мовний рандом
	{
		short random_language = 1 + rand() % (6 - 1 + 1);
		switch (random_language)
		{
		case 1: //перший мовний діапазон(знак оклику)
		{
			falling_symbol.s = first_diapazone_verbal;
			break;
		}
		case 2: //другий мовний діапазон(кома)
		{
			falling_symbol.s = second_diapazone_verbal;
			break;
		}
		case 3: //третій мовний діапазон(крапка)
		{
			falling_symbol.s = third_diapazone_verbal;
			break;
		}
		case 4: //четвертий мовний діапазон(знак питання)
		{
			falling_symbol.s = fourth_diapazone_varbal;
			break;
		}
		case 5: //п'ятий мовний діапазон (великі літери)
		{
			falling_symbol.s = min_fifth_diapazone_verbal + rand() % (max_fifth_diapazone_verbal - min_fifth_diapazone_verbal + 1);
			break;
		}
		case 6: //шостий мовний діапазон (малі літери)
		{
			falling_symbol.s = min_sixth_diapazone_verbal + rand() % (max_sixth_diapazone_verbal - min_sixth_diapazone_verbal + 1);
			break;
		}
		}
		break;
	}
	}
}
