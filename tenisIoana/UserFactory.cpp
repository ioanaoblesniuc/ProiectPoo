#include "UserFactory.h"


UserFactory::UserFactory(void)
{
}


UserFactory::~UserFactory(void)
{
}

_CUser* UserFactory::Create_User(char*tip)
{
	if(strcmp(tip,"admin")==0)
	{
		return Admin::getInstance(tip);
	}
	else if(strcmp(tip,"client") == 0)
	{
		return new Client(tip);
	}
	throw new CExceptie(ERR_NON_EXISTENT,"Tip de user nesuportat");
}
