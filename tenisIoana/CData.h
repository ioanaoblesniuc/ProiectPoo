#pragma once
#include "Util.h"
class CData
{
	int _mZi;
	int _mLuna;
	int _mAn;
public:
	CData();
	CData(int,int,int);
	CData(const CData& data);
	void setData(int,int,int);
	static CData fromString(const string&); // format zz::ll::yyyy
	CData& getData() const;
	int getZi() const;
	int getLuna() const;
	int getAn() const;
	
	void printData();

	bool operator==(CData& X);
	bool operator<(CData& X);
	bool operator>(CData& X);

	~CData(){}

};