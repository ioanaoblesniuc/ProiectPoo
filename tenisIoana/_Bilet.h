#pragma once
#include "_CUser.h"
class _Bilet
{
protected:
	string _mID;
	string _mClasaRezervare;
	bool _mDisponibil;
	int _mPret;
	_CUser* _mDateClient;
public:
	_Bilet();
	_Bilet(char*,char*,int);

	void setID(char*);
	void setClasaRezervare(char*);
	void setPret(int);
	void setDisponibil(bool);
	void setDateClient(_CUser*);

	string getID() const;
	string getClasaRezervare() const;
	int getPret() const;
	bool getDisponibil()const;
	Client getDateClient() const;

	void Rezervare();
	void AnuleazaRezervarea();

	virtual ~_Bilet(){}
};

class BiletIeftin:public _Bilet
{
protected:
	bool _mPliante;
public:
	BiletIeftin();
	BiletIeftin(char*,int,bool);

	void setPliante(bool);
	bool getPliante()const;

	virtual ~BiletIeftin(){}
};

class BiletScump:public _Bilet
{
protected:
	bool _mMasa;
	bool _mBautura;
public:
	BiletScump();
	BiletScump(char*,int,bool,bool);

	void setMasa(bool);
	void setBautura(bool);
	void getMasa() const;
	void getBautura() const;

	virtual ~BiletScump(){}
};

