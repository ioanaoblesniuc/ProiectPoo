#pragma once
#include "CString.h"
class Player
{
	int GlobalRank;
	CString name;
	int sex;
	CString tara;
public:
	Player(void);
	~Player(void);
	CString toString();
};

