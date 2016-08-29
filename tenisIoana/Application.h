#pragma once
#include "_CUser.h"
#include "Tournement.h"
#include  "Ticket.h"
#include "AppConfig.h"
#include "Companies.h"
class Application
{
	std::list<Tournement> tournements;
	Companie flightCompany;
	_CUser *ptrUserLogged;
	AppConfig config;
	void Load();
public:
	void Login(const CString&,const CString&,const CString&,const CString&);
	void Register(const CString&,const CString&,const CString&,const CString&);
	void Book (Tournement&,Ticket&);
	Application(void);
	~Application(void);
};

