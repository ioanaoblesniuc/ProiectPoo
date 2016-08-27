#include "CString.h"
#include "Util.h"
#include<iostream>
using namespace std;

CString::CString()
{
	this->s = NULL;
}

CString::CString(char *sir)
{
	this->s = new char[strlen(sir)+1];
	strcpy(this->s,sir);
	CHECK_ALLOC(s);
}

CString CString::operator=(char* sir)
{
	this->s = new char[strlen(sir)+1];
	strcpy(this->s,sir);
	CHECK_ALLOC(s);
}

bool CString::operator==(CString sir)
{
	char *ac = new char[this->get_len()+1];
	strcpy(ac,this->s);
	char *bc = new char[sir.get_len()+1];
	strcpy(bc,sir.s);
	if (strcmp(ac,bc)==0)
		return true;
	return false;
}

CString& CString::operator+(CString& sir)
{
	CString* t = new CString(this->s);
	strcat(t->s,sir.s);
	return *t;
}

CString& CString::operator+(char ch)
{
	CString* t = new CString(this->s);
	char *temp = new char(2); //one for extra char,one for trailing zero;
	temp[0] = ch;
	temp[1] = '\0';
	strcat(t->s,temp);
	return *t;
}

void CString::print()
{
	cout << this->s << endl;
}

void CString::set_data(char* sir)
{
	if (this->s)
		delete this->s;
	this->s = new char(strlen(sir)+1);
	strcpy(this->s,sir);
	CHECK_ALLOC(s);
}

int CString::get_len() const
{
	return strlen(this->s);
}

char* CString::get_data() const
{
	return this->s;
}


CString::~CString() {}