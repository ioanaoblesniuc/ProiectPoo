#include "Application.h"


Application::Application(void)
{
	config.setup();
	Load();
}


Application::~Application(void)
{
}

void Application :: Load()
{

}

void Application::Login(const char* Username, const char* Password, const char* Question, const char* Answer)
{
	char* Path_Users = this->config.get(Properties::PATH_USERS);

	FILE *f = fopen(Path_Users, "r");
	char buffer[180];
	vector<string> out;
	while (!feof(f))
	{
		fgets(buffer, 180, f);
		string s(buffer);
		Util::split(s,'*', out);
		if (Username == out[1] && Password == out[2] && Question == out[3] && Answer == out[4])
		{
			// logged User
			ptrUserLogged = UserFactory::Create_User((char*)out[0].c_str());
			ptrUserLogged->setUsername((char*)Username);
			ptrUserLogged->setPassword((char*)Password);
			ptrUserLogged->setQuestion((char*)Question);
			ptrUserLogged->setAnswer((char*)Answer);
			ptrUserLogged->setAdresaClient((char*)out[5].c_str(), (char*)out[6].c_str(), (char*)out[7].c_str(), atoi((char*)out[8].c_str()));
			ptrUserLogged->setEmail((char*)out[9].c_str());			
			ptrUserLogged->setTelefon((char*)out[10].c_str());
			return;
		}
	}
	throw new CExceptie(ERR_ACCESS_FORBIDDEN, "Login failed");
}
_CUser* Application::Register(const char* Username, const char* Password, const char* Question, const char* Answer, bool Admin)
{
	_CUser * user = nullptr;
	switch (Admin)
	{
		case  true:
			user = UserFactory::Create_User("admin");
			break;
		case false:
			user = UserFactory::Create_User("client");
			break;
	}
	user->setUsername((char*)Username);
	user->setPassword((char*)Password);
	user->setQuestion((char*)Question);
	user->setAnswer((char*)Answer);
	return user;
}

void Application::RegisterInfo(_CUser* user, const char* Country, const char* Locality, const char* street, int number, const char* email, const char*phone)
{
	user->setAdresaClient((char*)Country, (char*)Locality, (char*)street, (atoi)((char*)number));
	user->setEmail((char*)email);
	user->setTelefon((char*)phone);

}