#include "Tournement.h"


Tournement::Tournement(void)
{
}


Tournement::~Tournement(void)
{
}

void Tournement::load(const char* path)
{
	FILE * f = fopen(path, "r");
	std::vector<string> s;
	while (!feof(f))
	{
		Game *g = new Game();
		char buffer[100];
		fgets(buffer, 100, f);
		Util::split(buffer, '*', s);
		

	}
}