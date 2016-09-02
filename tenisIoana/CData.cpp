#include "cdata.h"


CData::CData(const CData& data)
{
	this->_mAn = data._mAn;
	this->_mLuna = data._mLuna;
	this->_mZi = data._mZi;
}
CData::CData()
{
	this->_mAn = 0;
	this->_mLuna = 0;
	this->_mZi = 0;
}

CData CData::fromString(const string& rhs)
{
	vector<string> s;
	Util::split(rhs, ':', s);
	return *new CData(atoi(s[0].c_str()), atoi(s[1].c_str()), atoi(s[2].c_str()));
}

CData::CData(int zi, int luna, int an)
{
	this->_mZi = zi;
	this->_mLuna = luna;
	this->_mAn = an;
}