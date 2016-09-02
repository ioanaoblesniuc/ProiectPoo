#include "string.h"
#include <list>
#include "Zbor.h"

class Companie
{
	string _mNume;
	int _mTimpRezervare;
	list<CZbor> _mZboruri;
public:
	Companie();
	Companie(char*,int);
	void setNume(char*);
	void setTimp(int);
	string& getNume()const;
	int getTimp()const;
	void printFlight(char*,char*);
	void printFlight(char*);
	int addRezervare(char* idZbor,char*idLoc);
	void loadFlights(char*,int);
	void insertFlight(char*);
	void deleteFlight(char*);
	string& generareIDFlight();
	void printFlightScedule();
	virtual ~Companie();
};


