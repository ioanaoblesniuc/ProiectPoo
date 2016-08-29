#include "BiletFactory.h"



Bilet* BiletFactory::Create_Bilet(TypeBilet bilet,char*,int,bool)
{
	switch (bilet)
	{
		case TypeBilet::BiletIeftin:
				  return NULL;
		case TypeBilet::BiletScump:
				  return NULL;
		default:
			throw new CExceptie(ERR_NON_EXISTENT,"Tip de bilet neexistent");
	}
}