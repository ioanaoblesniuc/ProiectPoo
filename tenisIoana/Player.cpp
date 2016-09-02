#include "Player.h"


Player::Player(string& nume)
{
	this->name = nume;
}


Player::~Player(void)
{
}

void Player::setNume(string& nume)
{
	this->name = nume;
}

string Player::getNume()
{
	return this->name;
}

Player::Player(std::string& rhs, int sex, int globalRank, string tara)
{
	this->name = rhs;
	this->sex = sex;
	this->GlobalRank = globalRank;
	this->tara = tara;
}