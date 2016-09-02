#include "CExceptie.h"
#include<string.h>
#include<stdlib.h>

CExceptie::CExceptie(int code, char* message)
{
	mCod = code;
	mMesaj = _strdup(message);
	mArgOb = NULL;
}

CExceptie::CExceptie(int code,char* message,void* argObj)
{
	mCod = code;
	mMesaj = _strdup(message);
	mArgOb = argObj;
}

CExceptie::~CExceptie()
{
	if (mMesaj)
		free(mMesaj);
}


int CExceptie::getCod()
{
	return mCod;
}

char* CExceptie::getMesaj()
{
	return mMesaj;
}

void* CExceptie::getArgObj()
{
	return mArgOb;
}
