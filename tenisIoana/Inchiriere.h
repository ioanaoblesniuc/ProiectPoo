#pragma once
#include "CString.h"
#include <list>
class Inchiriere
{
public:

	int _mNrLocuri;
	int _mNrLocuriLibere;
	int _mPret;

	Inchiriere(void);
	Inchiriere(int,int,int);

	void setNrLocuri(int);
	void setNrLocuriLibere(int);
	void setPret(int);

	int getNrLocuri() const;
	int getNrLocuriLibere() const;
	int getPret() const;

	virtual ~Inchiriere(){}
};

