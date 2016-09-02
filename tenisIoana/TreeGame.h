#pragma once
#include "Game.h"
class TreeGame
{
	std::vector<TenisCourt*> availableCourts;
	Game * root;
	Game* buildTree(std::vector<Player*>* list);
public:
	TreeGame(char* pathPlayers,char* pathsCourts);
	TreeGame(std::vector<Player*>* names);
	Game* TreeGame::find(Game *start, string player);
	Game* GetByName(string player);
	void AddGames(const char*);
	~TreeGame();
};

