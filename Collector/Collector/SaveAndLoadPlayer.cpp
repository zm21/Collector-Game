#include "SaveAndLoadPlayer.h"
bool Save_players_to_file(Player*  players, const int & PLAYER_AMOUNT)
{
	if (PLAYER_AMOUNT > 0)
	{
		ofstream save_players;
		save_players.open("players.bin", ios_base::out | ios_base::binary);
		if (save_players.is_open())
		{
			save_players.write((char*)&PLAYER_AMOUNT, sizeof(int));
			for (int i = 0; i < PLAYER_AMOUNT; i++)
			{
				save_players.write((char*)&players[i], sizeof(Player));
			}
			save_players.close();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Load_players_from_file(Player* & players, int & PLAYER_AMOUNT)
{
		ifstream load_players;
		load_players.open("players.bin", ios_base::in | ios_base::binary);
		if (load_players.is_open())
		{
			load_players.read((char*)&PLAYER_AMOUNT, sizeof(int));
			players = (Player*)realloc(players, sizeof(Player)*(PLAYER_AMOUNT));
			for (int i = 0; i < PLAYER_AMOUNT; i++)
				load_players.read((char*)&players[i], sizeof(Player));
			load_players.close();
			return true;
		}
		else
		{
			return false;
		}
}

bool Load_player_amount(int&PLAYER_AMOUNT)
{
	ifstream load;
	load.open("players.bin", ios_base::in | ios_base::binary);
	if (load.is_open())
	{
		load.read((char*)&PLAYER_AMOUNT, sizeof(int));
		load.close();
		return true;
	}
	else
	{
		return false;
	}
}

void Sort_player(Player*&players, const int &PLAYER_AMOUNT)
{
	for (int i = 0; i < PLAYER_AMOUNT; i++)
	{
		int index_max_score = i;
		int max_score = players[i].best_score;
		for (int j = i+1; j < PLAYER_AMOUNT; j++)
		{
			if (max_score < players[j].best_score)
			{
				max_score = players[j].best_score;
				index_max_score = j;
			}
		}
		swap(players[i], players[index_max_score]);
	}
}

void Add_player( char* player_name, int score, Player*&players, int &PLAYER_AMOUNT)
{
	int player_index{};
	bool player_found=false;
	for (int i = 0; i < PLAYER_AMOUNT; i++)
	{
		if (strcmp(players[i].player_name, player_name) == NULL)
		{
			player_found = true;
			player_index = i;
			break;
		}

	}
	if (!player_found)
	{
		players = (Player*)realloc(players, sizeof(Player)*(PLAYER_AMOUNT + 1));
		for (int i = 0; i < strlen(player_name); i++)
		{
			players[PLAYER_AMOUNT].player_name[i] = player_name[i];
		}
		players[PLAYER_AMOUNT].player_name[strlen(player_name)] = '\0';
		players[PLAYER_AMOUNT].best_score = score;
		PLAYER_AMOUNT += 1;
	}
	else
	{
		if (score > players[player_index].best_score)
		{
			players[player_index].best_score = score;
		}
	}
	if (PLAYER_AMOUNT > 1)
	{
		Sort_player(players, PLAYER_AMOUNT);
	}
	Save_players_to_file(players, PLAYER_AMOUNT);
}

void Create_arr_players(Player*&players, int &PLAYER_AMOUNT)
{
	free(players);
	Player* players_n ;
	players_n = (Player*)malloc(sizeof(Player));
	players = players_n;
	PLAYER_AMOUNT = 0;
}