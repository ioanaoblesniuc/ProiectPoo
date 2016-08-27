#include "UserFactory.h"


UserFactory::UserFactory(void)
{
}


UserFactory::~UserFactory(void)
{
}

CUser* UserFactory::Create_User(char*tip)
{
	if(strcmp(tip,"Admin"))
	{
		return Admin::getInstance(tip);
	}
	else if(strcmp(tip,"Client"))
	{
		return new Client(tip);
	}
	throw new CExceptie(ERR_NON_EXISTENT,"Tip de user nesuportat");
}
