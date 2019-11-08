#include "Drop.h"

void Ini_falling_symbol(Drop &falling_symbol)
{
	int action = 1 + rand() % (2 - 1 + 1);
	//������ ������� �� ASCII TABLE
	switch (action)
	{
	case 1: //������������ ������
	{
		short math_random = 1 + rand() % (4 - 1 + 1); //������ �������� 
		switch (math_random)
		{
		case 1: //������ ������������ ������� (��������, ���������, �����)
		{
			falling_symbol.s = min_first_diapazone_math + rand() % (max_first_diapazone_math - min_first_diapazone_math + 1);
			break;
		}
		case 2: //������ ������������ �������(������� ����� ���� ��������)
		{
			falling_symbol.s = second_diapazone_math;
			break;
		}
		case 3: //����� ������������ �������(���� ������ �� ����� �� 0 �� 9)
		{
			falling_symbol.s = min_third_diapazone_math + rand() % (max_third_diapazone_max - min_third_diapazone_math + 1);
			break;
		}
		case 4: //��������� ������������ ������� (�����)
		{
			falling_symbol.s = min_fourth_diapazone_math + rand() % (max_fourth_diapazone_math - min_fourth_diapazone_math + 1);
			break;
		}
		}
		break;
	}
	case 2: //������ ������
	{
		short random_language = 1 + rand() % (6 - 1 + 1);
		switch (random_language)
		{
		case 1: //������ ������ �������(���� ������)
		{
			falling_symbol.s = first_diapazone_verbal;
			break;
		}
		case 2: //������ ������ �������(����)
		{
			falling_symbol.s = second_diapazone_verbal;
			break;
		}
		case 3: //����� ������ �������(������)
		{
			falling_symbol.s = third_diapazone_verbal;
			break;
		}
		case 4: //��������� ������ �������(���� �������)
		{
			falling_symbol.s = fourth_diapazone_varbal;
			break;
		}
		case 5: //�'���� ������ ������� (����� �����)
		{
			falling_symbol.s = min_fifth_diapazone_verbal + rand() % (max_fifth_diapazone_verbal - min_fifth_diapazone_verbal + 1);
			break;
		}
		case 6: //������ ������ ������� (��� �����)
		{
			falling_symbol.s = min_sixth_diapazone_verbal + rand() % (max_sixth_diapazone_verbal - min_sixth_diapazone_verbal + 1);
			break;
		}
		}
		break;
	}
	}
}
