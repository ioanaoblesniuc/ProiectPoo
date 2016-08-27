#pragma once
#include "_CUser.h"s
class UserFactory
{
	static CUser* Create_User(char*tip);
public:
	UserFactory(void);
	~UserFactory(void);
};

