#include "CString.h"
#include "CExceptie.h"
#include<iostream>
using namespace std;
#include<string>


class CUser
{
	
public:
	virtual void Login() = 0;
	virtual void Logout() = 0;
	virtual void Register() = 0;
	virtual CString& getUsername() const = 0;
	virtual CString& getPassword() const = 0;
	virtual CString& getQuestion() const = 0;
	virtual CString& getAnswer() const = 0;
	virtual bool Check_username(char*) = 0;
	virtual void load(char*) = 0;
};

class CNewUser
{
public:
	static CUser* Create_Admin(char*);
	static CUser* Create_Client(char*);
};