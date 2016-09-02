#pragma once
#include "includes.h"
class Player
{
	int GlobalRank;
	string name;
	int sex;
	string tara;
public:
	Player(std::string&);
	Player(std::string&,int sex,int globalRank,string tara);
	~Player(void);
	void setNume(string& nume);
	string getNume();
	string toString();
};

