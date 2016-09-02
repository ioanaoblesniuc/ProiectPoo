#pragma once
#include "includes.h"
#include "CExceptie.h"

class CStrada
{
	string* _mNume;
	int _mNr;
public:
	CStrada();
	CStrada(char*,int);

	void setNume(char*);
	void setNr(int);

	string& getNume() const;
	int getNr() const;

	virtual ~CStrada();

};
