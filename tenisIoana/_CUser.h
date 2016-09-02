#pragma once
#include "CAdresa.h"
#include "includes.h"
class _CUser
{
protected:
	string* _mTip;
	bool _mConected;
	string* _mUsername;
	string* _mPassword;
	string* _mQuestion;
	string* _mAnswer;
public:
	_CUser();
	_CUser(char*,char*,char*,char*,char*);
	void setTip(char*);
	void setUsername(char*);
	void setPassword(char*);
	void setQuestion(char*);
	void setAnswer(char*);
	string& getUsername()const;
	string& getPassword() const;
	string& getQuestion() const;
	string& getAnswer() const;
	bool Check_username(char*);
	bool Check_password(char*);
	bool Check_answer(char*);
	void Modify_password(char*);
	void Forget_password();
	void Reset_password();
	void Login();
	void Logout();
	virtual void Register()=0;
	virtual void load(char*)=0;
	virtual void setAdresaClient(char* tara, char* loc, char* str, int nr) = 0;
	virtual void setEmail(char*) = 0;
	virtual void setTelefon(char*) = 0;
	virtual ~_CUser();
	virtual std::string toString()=0;
};

class Client:public _CUser
{
	CAdresa* _mAdresaClient;
	string* _mEmail;
	string* _mTelefon;
public:
	Client();
	Client(char* tip);
	void setAdresaClient(char*,char*,char*,int);
	void setEmail(char*);
	void setTelefon(char*);
	void Register();
	void load(char* filename);
	virtual std::string toString();
	//ce am in cos
	void setCos();
	virtual ~Client();
};

class Admin:public _CUser
{
	static Admin *_mInstance;
	Admin();
	Admin(char* tip);
	~Admin();

public:
	static Admin* getInstance(char*);
	static void DestroyInstance();
	void Register();
	void load(char*){}
	//not allowed methods
	void setAdresaClient(char* tara, char* loc, char* str, int nr);
	void setEmail(char*);
	void setTelefon(char*);
	virtual std::string toString();
};