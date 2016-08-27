#include "CStrada.h"
#include<iostream>
using namespace std;

CStrada::CStrada()
{
	_mNume = NULL;
	_mNr = 0;
}

CStrada::CStrada(char* nume,int nr)
{
	_mNume = new CString(nume);
	setNr(nr);
}

void CStrada::setNume(char* nume)
{
	_mNume->set_data(nume);
}

void CStrada::setNr(int nr)
{
	_mNr = nr;
}

CString& CStrada::getNume() const
{
	return *_mNume;
}

CStrada::~CStrada()
{
	if(_mNume)
		delete _mNume;
}