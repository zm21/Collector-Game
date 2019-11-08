#pragma once
struct Collector_settings //структура самого коллектора
{
	char s = 'U'; // "скін" (символ, вигляд) коллектора
	int x = 15; //вісь руху коллектора
	int const y = 24; //висота на якій рухається коллектор
};
namespace 
{
	Collector_settings collector;
}
	enum Collector_direction
	{
		move_left = 'a', move_right = 'd'
	};