#include "Game.h"

int	Game::getLevel()
{
	return this->level;
}

Game::Game(void)
{
	this->m_Left = NULL;
	this->m_Right = NULL;
	this->scores = NULL;
}

Game::Game(const Game & rhs)
{
	*this->m_Left = *rhs.m_Left;
	*this->m_Right = *rhs.m_Right;
	*this->player = *rhs.player;
	*this->scores = *rhs.scores;
	this->data = (CData)rhs.data;
}
Game::~Game(void)
{
	if (m_Left)
		delete m_Left;
	if (m_Right)
		delete m_Right;
	if (scores)
		delete scores;
}

Game::Game(Game* left, Game* right)
{
	this->player->setNume(string(""));
	m_Left = left;
	m_Right = right;
	m_Left->parent = this;
	m_Right->parent = this;
}

Game* Game::getPlayerLeft()
{
	return this->m_Left;
}
Game* Game::getPlayerRight()
{
	return this->m_Right;
}

Player* Game::getPlayer()
{
	return this->player;
}
Game::Game(Player*player)
{
	this->player = player;
	this->m_Left = NULL;
	this->m_Right = NULL;
}
Game* Game::load(FILE* f)
{
	return nullptr;
}