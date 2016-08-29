#pragma once
#include "Game.h"
class Tournement
{
	std::list<Game> games; 
	CString locatie;
public:
	void fill();
	Tournement(void);
	~Tournement(void);
};

