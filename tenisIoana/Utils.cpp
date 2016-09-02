#include "Util.h"

void* myrealloc(void* ptr, int actualSize, int newSize)
{
	unsigned char* aux = NULL;

	if(actualSize>0)
	{
		aux = new unsigned char[actualSize];
		CHECK_ALLOC(aux);
		memcpy(aux,ptr,actualSize);
		delete [] ptr;
	}

	ptr = (void*)new unsigned char[newSize];
	CHECK_ALLOC(ptr);

	if(actualSize >0)
	{
		memcpy(ptr,aux,actualSize);
		delete [] aux;
	}

	return ptr;

}