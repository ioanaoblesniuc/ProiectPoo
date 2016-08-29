#include "_Bilet.h"
#include "CExceptie.h"


_Bilet::_Bilet():_mDateClient()
{
	setID("00");
	setClasaRezervare("");
	setPret(0);
	setDisponibil(true);
}


_Bilet::~_Bilet(void)
{
}
