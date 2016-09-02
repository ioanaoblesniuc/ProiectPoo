#pragma once
#include "_Bilet.h"
#include "TypeBilet.h"
class BiletFactory
{
public:
	static _Bilet* Create_Bilet(TypeBilet,char*,int,bool);
};

