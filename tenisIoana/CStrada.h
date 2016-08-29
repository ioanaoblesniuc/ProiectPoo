#pragma once
#include "CString.h"
#include "CExceptie.h"

class CStrada
{
	CString* _mNume;
	int _mNr;
public:
	CStrada();
	CStrada(char*,int);

	void setNume(char*);
	void setNr(int);

	CString& getNume() const;
	int getNr() const;

	virtual ~CStrada();

};
