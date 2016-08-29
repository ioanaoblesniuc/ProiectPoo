#pragma once
#include "CUser.h"
#include "CAdresa.h"

class _CUser:public CUser
{
protected:
	CString* _mTip;
	bool _mConected;
	CString* _mUsername;
	CString* _mPassword;
	CString* _mQuestion;
	CString* _mAnswer;
public:
	_CUser();
	_CUser(char*,char*,char*,char*,char*);

	void setTip(char*);
	void setUsername(char*);
	void setPassword(char*);
	void setQuestion(char*);
	void setAnswer(char*);

	CString& getUsername()const;
	CString& getPassword() const;
	CString& getQuestion() const;
	CString& getAnswer() const;
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

	virtual ~_CUser();
};

class Client:public _CUser
{
	CAdresa* _mAdresaClient;
	CString* _mEmail;
	CString* _mTelefon;
public:
	Client();
	Client(char* tip);

	void setAdresaClient(char*,char*,char*,int);
	void setEmail(char*);
	void setTelefon(char*);

	void Register();
	void load(char* filename);

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
};