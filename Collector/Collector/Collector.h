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
	move_left = 'a', move_right = 'd',
	big_move_distance = 3,
	big_move_left = 'j', big_move_right = 'l',
};