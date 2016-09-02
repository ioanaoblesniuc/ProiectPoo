#include "_Bilet.h"
#include "CExceptie.h"


_Bilet::_Bilet():_mDateClient()
{
	setID("00");
	setClasaRezervare("");
	setPret(0);
	setDisponibil(true);
}


void _Bilet::setID(char* id)
{
	this->_mID.assign(id, strlen(id));
}
void _Bilet::setClasaRezervare(char* clasa)
{
	this->_mClasaRezervare.assign(clasa, strlen(clasa));
}
void _Bilet::setPret(int pret)
{
	this->_mPret = pret;
}
void _Bilet::setDisponibil(bool disp)
{
	this->_mDisponibil = disp;
}
void _Bilet::setDateClient(_CUser* date)
{
	*this->_mDateClient = *date;
}