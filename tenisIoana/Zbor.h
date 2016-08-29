#include "CString.h"
#include<list>
#include "_Bilet.h"
#include "Inchiriere.h"
#include "Ora.h"
#include "CData.h"

class CZbor
{
	CString* _mID;
	CString* _mLocatie;
	CString* _mDestinatie;
	CData* _mData;
	COra* _mOraPlecare;
	COra* _mOraSosire;
	list<Bilet*> _mLocuri;
	int _mNrLocuri;
	Inchiriere _mScump;
	Inchiriere _mIeftin;
	list<string> _mListaAsteptare;

public:
	CZbor();
	CZbor(char*,char*,char*,CData,COra,COra,int,int,int);
	void setID(char*);
	void setLocatie(char*);
	void setDestinatie(char*);
	void setData(CData);
	void setOraPlecare(COra);
	void setOraSosire(COra);
	void setNrLocuri(int);
	void setPretIeftin(int);
	void setPretScump(int);

	CString& getID()const;
	CString& getLocatie() const;
	CString& getDestinatie() const;
	CData& getData()const;
	COra& getOraPlecare()const;
	COra& getOraSosire()const;
	int getNrLocuri()const;
	bool getAvailable()const;
	void GenerareLocuri();
	void printLocuriLibere();
	void addRezervare(char*);
	void AnuleazaRezervare(CString);
	void addClientiAsteptare();
	void printDetalii();

	virtual ~CZbor(){}
};

