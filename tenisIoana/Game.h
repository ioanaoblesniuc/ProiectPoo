#pragma once
#include "Player.h"
#include "TenisCourt.h"
#include "CData.h"
#include "Ora.h"
#include "Score.h"
class Game
{
	Player* player1;
	Player* player2;
	TenisCourt arena;
	int level;
	Score* scores;
	bool isLive;
	COra ora;
	CData data;
public:
	Game(void);
	~Game(void);
};

