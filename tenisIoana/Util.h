#pragma once
#include "CExceptie.h"
#include "includes.h"



class Util {
public:
	static void  split(const string &s, char delim, vector<string> &elems) {
		stringstream ss;
		ss.str(s);
		string item;
		while (getline(ss, item, delim)) {
			elems.push_back(item);
		}
	}
	static int randInt(int low, int high)
	{
		// Random number between low and high
		return rand() % ((high + 1) - low) + low;
	}
};

#define CHECK_ALLOC(ptr)\
	if (ptr == NULL)\
	  throw new CExceptie(ERR_ALLOC,"Nu s-a putut aloca memorie");


void* myrealloc(void *ptr, int actualSize, int newSize);