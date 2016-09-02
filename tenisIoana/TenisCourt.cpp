#include "TenisCourt.h"

TenisCourt::TenisCourt(char* name, int capacity, int noSectors)
{
	this->name = name;
	this->Capacity = capacity;
	this->noSectors = noSectors;
}

TenisCourt::TenisCourt()
{
	this->name = "";
	this->Capacity = 0;
	this->noSectors = noSectors;
}

TenisCourt* TenisCourt::load(FILE*f)
{
	char name[40];
	int capacity=0;
	int sectors=0;
	fgets(name, 100, f);
	places.clear();
	fscanf(f, "%d", &capacity); fscanf(f, "%d", &sectors);
	for (int i = 0; i < sectors * capacity; i++)
	{
		char status = 0;
		fscanf(f, "%c",&status);
		bool busy = status == '1';
		Place *p = new Place(i% sectors,i/sectors,busy);
		addNewPlace(p);
	}
	return this;
}

bool TenisCourt::isEmpty(int sector, int number)
{
	auto  p = std::find_if(this->places.begin(), this->places.end(), [&]( Place& place)
	{
		return place.getSector() == sector &&
			place.getNumber() == number;
	});
	if (p->isBusy()) return false;
	return true;
}

void TenisCourt::markBusy(int sector, int number)
{
	auto  p = std::find_if(this->places.begin(), this->places.end(), [&]( Place& place)
	{
		return place.getSector() == sector &&
			place.getNumber() == number;
	});
	p->setBusy();
}

void TenisCourt::addNewPlace(Place *p)
{
	this->places.push_back(*p);
}

void TenisCourt::store(const char* file)
{
	FILE * f = fopen(file, "w");
	char buffer[3000];
	for (int i = 0; i < this->noSectors; i++)
	{
		sprintf(buffer, "%s", this->name.c_str());
		sprintf(buffer, "%d", this->Capacity);
		sprintf(buffer, "%d", this->noSectors);
		for (auto it = places.begin(); it != places.end(); it++)
		{
			if ((*it).isBusy())
				sprintf(buffer, "%c", '0');
			else
				sprintf(buffer, "%c", '1');
		}
		fputs(buffer, f);
	}
}

