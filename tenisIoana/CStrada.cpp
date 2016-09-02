#include "CStrada.h"

CStrada::CStrada()
{
	_mNume = NULL;
	_mNr = 0;
}

CStrada::CStrada(char* nume,int nr)
{
	_mNume = new string(nume);
	setNr(nr);
}

void CStrada::setNume(char* nume)
{
	*_mNume = nume;
}

void CStrada::setNr(int nr)
{
	_mNr = nr;
}

string& CStrada::getNume() const
{
	return *_mNume;
}

CStrada::~CStrada()
{
	if(_mNume)
		delete this->_mNume;
}