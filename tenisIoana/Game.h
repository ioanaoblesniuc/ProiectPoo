#pragma once
#include "Player.h"
#include "TenisCourt.h"
#include "CData.h"
#include "Ora.h"
#include "Score.h"
class Game
{
	Game* m_Left;
	Game* m_Right;
	Game* parent;
	Player* player;
	TenisCourt* arena;
	int level;
	Score* scores;
	bool isLive;
	COra ora;
	CData data;
public:
	Game* getPlayerLeft();
	Game* getPlayerRight();
	Player* getPlayer();
	int		getLevel();
	Game* load(FILE*);
	Game(Game*,Game*);
	Game(const Game & rhs);
	Game(Player*player);
	~Game(void);
	Game();
private:

};

