#pragma once
#include "Place.h"
class TenisCourt
{
	CString name;
	int Capacity;
	list<Place> places;
public:
	bool isEmpty(int,int);
	void markBusy(int,int);
};

