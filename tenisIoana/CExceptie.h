#pragma once
#ifndef EXCEPTIE_H
#define EXCEPTIE_H
#include "Errors.h"

class CExceptie{
	int mCod;
	char *mMesaj;
	void *mArgOb;
public:
	CExceptie(int cod, char* mesaj);
	CExceptie(int cod, char* mesaj, void* argObj);
	~CExceptie();

	int getCod();
	char *getMesaj();
	void* getArgObj();
};

#endif