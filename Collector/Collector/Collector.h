#pragma once
struct Collector_settings //��������� ������ ����������
{
	char s = 'U'; // "���" (������, ������) ����������
	int x = 15; //��� ���� ����������
	int const y = 24; //������ �� ��� �������� ���������
};
namespace 
{
	Collector_settings collector;
}
	enum Collector_direction
	{
		move_left = 'a', move_right = 'd'
	};