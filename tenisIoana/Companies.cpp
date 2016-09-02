#include "Companies.h"

Companie::Companie()
{
	_mNume = "";
}
Companie::Companie(char* nume, int timp)
{
	this->_mNume.assign(nume, strlen(nume));
	this->_mTimpRezervare = timp;
}
Companie::~Companie()
{

}