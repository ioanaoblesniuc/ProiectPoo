#include "_CUser.h"

CUser* CNewUser::Create_Admin(char* tip)
{
	return Admin::getInstance(tip);
}

CUser* CNewUser::Create_Client(char* tip)
{
	return new Client(tip);
}

