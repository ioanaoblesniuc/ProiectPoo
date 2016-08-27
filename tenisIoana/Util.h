#include "CExceptie.h"
#include<stdlib.h>

#define CHECK_ALLOC(ptr)\
	if (ptr == NULL)\
	  throw new CExceptie(ERR_ALLOC,"Nu s-a putut aloca memorie");


void* myrealloc(void *ptr,int actualSize, int newSize);