#pragma once
#include "includes.h"
class Place
{
	int sector;
	int number;
	bool busy;
public:
	Place(int, int, bool);
	string toString();
	void setBusy();
	bool isBusy();
	void setEmpty();
	int getSector();
	int getNumber();
	bool operator==(Place& rhs);
};
