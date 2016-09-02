#include "CAdresa.h"

CAdresa::CAdresa():_mStrada()
{
	this->_mTara = NULL;
	this->_mLocalitate = NULL;
}

CAdresa::CAdresa(char *tara,char* loc,char* str,int nr)
{
	_mStrada = new CStrada(str,nr);
	_mTara = new string(tara);
	_mLocalitate = new string(loc);
}

void CAdresa::setTara(char* tara)
{
	_mTara->assign(tara,strlen(tara));
}

void CAdresa::setLocalitate(char *loc)
{
	_mLocalitate->assign(loc, strlen(loc));
}

void CAdresa::setStrada(char *nume,int nr)
{
	_mStrada->setNume(nume);
	_mStrada->setNr(nr);
}

string& CAdresa::getTara() const
{
	return *_mTara;
}

string& CAdresa::getLocalitate() const
{
	return *_mLocalitate;
}

CStrada& CAdresa::getStrada() const
{
	return *_mStrada;
}

CAdresa::~CAdresa()
{
	if ( _mTara )
		delete _mTara;
	if ( _mLocalitate )
		delete _mLocalitate;
	if ( _mStrada )
		delete _mStrada;
}