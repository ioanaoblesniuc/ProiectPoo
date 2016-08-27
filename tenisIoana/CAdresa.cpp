#include "CAdresa.h"
#include<iostream>
using namespace std;

CAdresa::CAdresa():_mStrada()
{
	_mTara = NULL;
	_mLocalitate = NULL;
}

CAdresa::CAdresa(char *tara,char* loc,char* str,int nr)
{
	_mStrada = new CStrada(str,nr);
	_mTara = new CString(tara);
	_mLocalitate = new CString(loc);
}

void CAdresa::setTara(char* tara)
{
	_mTara->set_data(tara);
}

void CAdresa::setLocalitate(char *loc)
{
	_mLocalitate->set_data(loc);
}

void CAdresa::setStrada(char *nume,int nr)
{
	_mStrada->setNume(nume);
	_mStrada->setNr(nr);
}

CString& CAdresa::getTara() const
{
	return *_mTara;
}

CString& CAdresa::getLocalitate() const
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