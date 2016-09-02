#include "Place.h"

string Place::toString()
{
	string s;
	s.append("Number = "); s.append(to_string(this->number)); s.append("\n");
	s.append("Sector = "); s.append(to_string(this->sector)); s.append("\n");
	s.append("Status = ");
	if (this->busy)
		s.append("Busy");
	else
		s.append("Free");
	s.append("\n");
	return s;
}
void Place::setBusy()
{
	this->busy = true;
}
bool Place::isBusy()
{
	return this->busy;
}
void Place::setEmpty()
{
	this->busy = false;
}
int Place::getSector()
{
	return this->sector;
}

int Place::getNumber()
{
	return this->number;
}

Place::Place(int sector, int number, bool busy)
{
	this->sector = sector;
	this->number = number;
	this->busy = busy;
}

bool Place::operator==(Place& rhs)
{
	return (this->number = rhs.getNumber() && this->sector == rhs.getSector());
}