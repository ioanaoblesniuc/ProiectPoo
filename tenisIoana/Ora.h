#pragma once
#include "Util.h"
class COra
{
	int _mOra;
	int _Min;
public:
	COra();
	COra(int,int);
	static COra fromString(const string& rhs);
	void setOra(int,int);
	COra& getOra() const;
	int _getOra() const;
	int getMin()const;

	void printOra();

	bool operator==(COra& X);

	~COra(){}
};