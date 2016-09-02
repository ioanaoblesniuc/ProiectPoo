#pragma once
#include "Util.h"
#include "Game.h"
class Tournement
{
	std::list<Game> games; 
	string locatie;
public:
	void load(const char* path);
	Tournement(void);
	~Tournement(void);
};

