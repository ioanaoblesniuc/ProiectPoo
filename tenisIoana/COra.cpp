#include "ora.h"

COra::COra()
{
	this->_Min = 0;
	this->_mOra = 0;
}

COra COra::fromString(const string& rhs)
{
	vector<string> s;
	Util::split(rhs, ':', s);
	return *new COra(atoi(s[0].c_str()), atoi(s[1].c_str()));
}

COra::COra(int ora, int min)
{
	this->_mOra = ora;
	this->_Min = min;
}