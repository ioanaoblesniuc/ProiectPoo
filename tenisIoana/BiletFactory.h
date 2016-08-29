#pragma once
#include "Bilet.h"
class BiletFactory
{
public:
	BiletFactory(void);
	~BiletFactory(void);
	static Bilet* Create_Bilet(TypeBilet,char*,int,bool);
};

