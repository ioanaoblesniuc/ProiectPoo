#pragma once
#include "_CUser.h"
#include "Tournement.h"
#include  "Ticket.h"
#include "AppConfig.h"
#include "Companies.h"
#include "UserFactory.h"
class Application
{
	std::list<Tournement> tournements;
	Companie flightCompany;
	_CUser *ptrUserLogged;
	AppConfig config;
	void Load();
public:
	void Login(const char*,const char*,const char*,const char*);
	_CUser* Register(const char* Username, const char* Password, const char* Question, const char* Answer,bool Admin);
	void RegisterInfo(_CUser*,const char* Country,const char* Locality,const char* street,int number,const char* email,const char*phone);
	void Book (Tournement&,Ticket&);
	Application(void);
	~Application(void);
};

