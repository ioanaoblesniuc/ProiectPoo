#pragma once
#include "Place.h"
class TenisCourt
{
	string name;
	int Capacity;
	int noSectors;
	list<Place> places;
public:
	TenisCourt(char*, int, int);
	TenisCourt();
	bool isEmpty(int,int);
	void markBusy(int,int);
	TenisCourt* load(FILE* f);
	void addNewPlace(Place *p);
	void store(const char* file);
};

