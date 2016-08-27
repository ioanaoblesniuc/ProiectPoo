#pragma once
#ifndef IOASTRING_H
#define IOASTRING_H
class CString
{
	char *s;
public:
	CString();
	CString(char *);
	CString operator=(char*);
	bool operator==(CString);
	bool operator==(char*);
	CString& operator+(CString&);
	CString& operator+(char*);
	CString& operator+(char);
	void print();
	void set_data(char*);
	int get_len() const;
	char *get_data() const;
	~CString();
};

#endif