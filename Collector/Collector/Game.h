#pragma once
#include "Drop.h"
#include "Collector.h"
#include "GamePrint.h"
#include <ctime>
#include <conio.h>
#include "SaveAndLoadPlayer.h"

enum Game_mode
{
	math_mode = 1, //������������ �����
	verbal_mode = 2 //������ �����
};
enum Score_and_life_inf
{
	score_add_default = 100, //�������� �������� ���� �� �������� ������
	score_boost_default = 1, //�������� �������� ����� (��� ��� ����� ��� � ��������� �������� �������� ������)
	life_default = 3 //����� �� ������� ���
};


void Start_play();

void Tracking_collerctor();
void Cathc_true_drop(Drop &falling_symbol);
void Cathc_false_drop(Drop &falling_symbol);
void No_cathc_true_drop(Drop &falling_symbol);
void No_cathc_false_drop(Drop &falling_symbol);