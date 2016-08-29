#include "_Bilet.h"


Bilet* BiletNou::Create_BiletScump(char* id,int pret,bool masa,bool bautura)
{
	return new BiletScump(id,pret,masa,bautura);
}

Bilet* BiletNou::Create_BiletIeftin(char* id,int pret,bool reviste)
{
	return new BiletIeftin(id,pret,reviste);
}