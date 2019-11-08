#pragma once
#include <Windows.h>
struct Drop
{
	char s;  //������ ���� ����
	int  x;  //������� ������ ��������
	int y; //������ ������ ��������
};
enum Math_mode_symbols_diapazone //ĳ������� ������� �� ASCII ��� ������������� ������ 
{
	min_first_diapazone_math = 40, max_first_diapazone_math = 43,  //������ ������������ ������� (��������, ���������, �����)
	second_diapazone_math = 45,									   //������ ������������ �������(������� ����� ���� ��������)
	min_third_diapazone_math = 47, max_third_diapazone_max = 57,   //����� ������������ �������(���� ������ �� ����� �� 0 �� 9)
	min_fourth_diapazone_math = 60, max_fourth_diapazone_math = 62 //��������� ������������ ������� (�����)
};
enum Verbal_mode_symbols_diapazone //ĳ������� ������� �� ASCII ��� ������� ������ 
{
	first_diapazone_verbal = 33,  //������ ������ �������(���� ������)
	second_diapazone_verbal = 44, //������ ������ �������(����)
	third_diapazone_verbal = 46,  //����� ������ �������(������)
	fourth_diapazone_varbal = 63, //��������� ������ �������(���� �������)
	min_fifth_diapazone_verbal = 65, max_fifth_diapazone_verbal = 90, //�'���� ������ ������� (����� �����)
	min_sixth_diapazone_verbal = 97, max_sixth_diapazone_verbal = 122 //������ ������ ������� (��� �����)
};
void Ini_falling_symbol(Drop &falling_symbol);