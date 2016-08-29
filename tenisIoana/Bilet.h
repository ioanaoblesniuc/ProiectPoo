#pragma once
#include "CString.h"
#include "TypeBilet.h"
#include "_CUser.h"

class Bilet
{
public:
	virtual bool getDisponibil() const = 0;
	virtual bool Rezervare() = 0;
	virtual void AnuleazaRezervare() = 0;
	virtual CString getID() const = 0;
};


class BiletNou
{
public:
	static Bilet* Create_BiletIeftin(char*,int,bool);
	static Bilet* Create_BiletScump(char*,int,bool,bool);
};
