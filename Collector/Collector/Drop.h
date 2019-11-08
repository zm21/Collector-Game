#pragma once
#include <Windows.h>
struct Drop
{
	char s;  //символ який падає
	int  x;  //позиція спавну предмету
	int y; //висота спавну предметів
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
void Ini_falling_symbol(Drop &falling_symbol);