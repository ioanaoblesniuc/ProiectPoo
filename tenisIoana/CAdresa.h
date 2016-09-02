#pragma once
#include "CExceptie.h"
#include "CStrada.h"
#include "includes.h"

//deci lucrez pe asta
//gen acum
//nu?dap haide sa adaugam o clasa.zi-mi tu un nume de clasa pe care vrei sa il adaugi clasa Bilet
class CAdresa
{
	string* _mTara;
	string* _mLocalitate;
	CStrada* _mStrada;
public:
	CAdresa();
	CAdresa(char*,char*,char*,int);

	void setTara(char*);
	void setLocalitate(char*);
	void setStrada(char*,int);

	string& getTara() const;
	string& getLocalitate() const;
	CStrada& getStrada() const;

	~CAdresa();
};