#pragma once
#include "_CUser.h"
class UserFactory
{
public:
	static _CUser* Create_User(char*tip);
public:
	UserFactory(void);
	~UserFactory(void);
};

