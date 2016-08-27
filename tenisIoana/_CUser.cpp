#include "_CUser.h"
#include "Util.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

_CUser::_CUser()
{
	_mConected = false;
	_mTip = NULL;
	_mUsername = NULL;
	_mPassword = NULL;
	_mQuestion = NULL;
	_mAnswer = NULL;

}

_CUser::_CUser(char* tip, char* name, char* pass, char* question,char* answ)
{
	_mConected = false;
	setTip(tip);
	setUsername(name);
	setPassword(pass);
	setQuestion(question);
	setAnswer(answ);
}


void _CUser::setTip(char *tip)
{
	if (_mTip)
		_mTip->set_data(tip);
	else
		_mTip = new CString(tip);
}

void _CUser::setUsername(char *name)
{
	if(_mUsername)
		_mUsername->set_data(name);
	else
		_mUsername = new CString(name);
}

void _CUser::setPassword(char* pass)
{
	if(_mPassword)
		_mPassword->set_data(pass);
	else
		_mPassword = new CString(pass);
}

void _CUser::setQuestion(char* question)
{
	if(_mQuestion)
		_mQuestion->set_data(question);
	else
		_mQuestion = new CString(question);
}

void _CUser::setAnswer(char* answer)
{
	if(_mAnswer)
		_mAnswer->set_data(answer);
	else
		_mAnswer = new CString(answer);
}

CString& _CUser::getUsername()const
{
	return *this->_mUsername;
}

CString& _CUser::getPassword() const
{
	return *this->_mPassword;
}

CString& _CUser::getQuestion()const
{
	return *this->_mQuestion;
}

CString& _CUser::getAnswer()const
{
	return *this->_mAnswer;
}

bool _CUser::Check_username(char* name)
{
	if (strcmp(_mUsername->get_data(),name)==0)
		return true;

	return false;
}

bool _CUser::Check_password(char* pass)
{
	if (strcmp(_mPassword->get_data(),pass)==0)
		return true;

	return false;
}

bool _CUser::Check_answer(char* answer)
{
	if ( strcmp(_mAnswer->get_data(),answer)==0)
		return true;

	return false;
}

void _CUser::Modify_password(char *newpass)
{
	if(_mConected == true)
		setPassword(newpass);
	else
		throw new CExceptie(ERR_ACCESS_FORBIDDEN,"Accesul interzis!");

}

void _CUser::Reset_password()
{
	char* newpass = new char[50];
	cout << "Introduceti o parola de cel mult 50 caractere"<< endl;
	CString pass = "";
	char ch;
	ch = _getch();
	while(ch!=13){
		pass = pass+ch;
		cout << '*';
		ch = _getch();
	}
	strcpy(newpass,pass.get_data());
	setPassword(newpass);
	cout << endl << "\t\tParola resetata cu succes!";
	cout << endl << "Bine ati venit, " << _mUsername->get_data() << "!!!" << endl;
	delete[] newpass;

}

void _CUser::Forget_password()
{
	bool ok = false;
	char* Answer = new char[255];
	for ( int i = 0; i < 3 ; i++ )
	{
		cout << endl << "\t Raspunsul la intrebarea : ";
		getQuestion().print();
		cin >> Answer;
		if (Check_answer(Answer) == true)
		{
			ok = true;
			break;
		}
	}
	if (ok == false)
		throw new CExceptie(ERR_DELETE,"Ati introdus raspunsul gresit de 3 ori!!!");
	else
	{
		_mConected = true;
		Reset_password();
	}
	delete[] Answer;
}

void _CUser::Login()
{
	char* passw = new char[256];
	cout << "\tIntroduceti parola:\n";
	CString pass = "";
	char ch;
	ch = _getch();
	while( ch!=13)
	{
		pass = pass + ch;
		cout << '*';
		ch = _getch();
	}
	strcpy(passw,pass.get_data());
	if( Check_password(passw)== true)
	{
		_mConected = true;
		cout << "Bine ati venit, " << _mUsername->get_data()<< "!" << endl;
		delete[] passw;
		return;
	}
	else
		Forget_password();
}

void _CUser::Logout()
{
	cout << endl << "\t\tLogout\n" << endl;
	cout << "\t Pa pa!";
}

_CUser::~_CUser()
{
	if(_mTip)
		delete _mTip;
	if(_mUsername)
		delete _mUsername;
	if(_mPassword)
		delete _mPassword;
	if(_mQuestion)
		delete _mQuestion;
	if(_mAnswer);
	delete _mAnswer;

}

Client::Client():_CUser()
{
	setTip("Client");
	_mAdresaClient = NULL;
	_mEmail = NULL;
	_mTelefon = NULL;
}

Client::Client(char* tip):_CUser()
{
	setTip(tip);
	_mAdresaClient = NULL;
	_mEmail = NULL;
	_mTelefon = NULL;

}
Client::~Client()
{
	if (_mAdresaClient )
		delete _mAdresaClient;
	if (_mEmail)
		delete _mEmail;
	if (_mTelefon)
		delete _mTelefon;
}

void Client::setAdresaClient(char* tara,char* loc,char* str,int nr)
{
	if (_mAdresaClient == NULL)
		_mAdresaClient = new CAdresa(tara,loc,str,nr);
	else
	{
		_mAdresaClient->setTara(tara);
		_mAdresaClient->setLocalitate(loc);
		_mAdresaClient->setStrada(str,nr);
	}
}

void Client::setEmail(char *email)
{
	if (_mEmail == NULL )
		_mEmail = new CString(email);
	else
	{
		_mEmail->set_data(email);
	}
}

void Client::setTelefon(char* telefon)
{
	if(_mTelefon == NULL)
		_mTelefon = new CString(telefon);
	else
	{
		_mTelefon->set_data(telefon);
	}
}

void Client::Register()
{
	FILE* f = fopen("useri.txt","a");
	fprintf(f,"\nClient ");
	char* username = new char[256];
	cout << endl << "Nume Utilizator:" << endl;
	cin >> username;
	setUsername(username);
	fprintf(f,"%s",username);
	fprintf(f," ");
	delete[] username;
	char* password = new char[256];
	cout << endl << "Parola:" << endl;
	CString pass = "";
	char ch;
	ch = _getch();
	while(ch!=13){
		pass = pass + ch;
		cout << '*';
		ch = _getch();
	}

	strcpy(password,pass.get_data());
	setPassword(password);
	fprintf(f,"%s",password);
	fprintf(f," ");
	delete[] password;
	char* question = new char[256];
	cout << endl << "Intrebare de securitate: " << endl;
	//gets(question);
	cin>>question;
	setQuestion(question);
	fprintf(f," ");
	delete[] question;

	char* answer = new char[256];
	cout << endl << "Raspunsul la intrebarea de scuritate:" << endl;
	cin >> answer;
	setAnswer(answer);
	fprintf(f,"%s",answer);
	fprintf(f," ");
	delete [] answer;
	char *tara = new char[256];
	cout << endl << "Tara:" << endl;
	cin >> tara;
	char *loc = new char[256];
	cout << endl << "Localitate: " << endl;
	cin >> loc;
	char* str = new char[256];
	cout << endl << "Strada:" << endl;
	cin >> str;
	int nr;
	cout << endl << "Numarul:" << endl;
	cin >> nr;
	this->setAdresaClient(tara,loc,str,nr);
	fprintf(f,"%s",tara);
	fprintf(f," ");
	fprintf(f,"%s",loc);
	fprintf(f," ");
	fprintf(f,"%s",str);
	fprintf(f," ");
	fprintf(f,"%d",nr);
	fprintf(f," ");
	delete[] tara;
	delete[] loc;
	delete[] str;
	char* email = new char[256];
	cout << endl << "Email:" << endl;
	cin >> email;
	this->setEmail(email);
	fprintf(f,"%s",email);
	fprintf(f," ");
	delete[] email;
	char *telefon = new char[256];
	cout << endl << "Telefon:" << endl;
	cin >> telefon;
	this->setTelefon(telefon);
	fprintf(f,"%s",telefon);
	fprintf(f," ");
	delete[] telefon;
	cout << endl << "\t\tBine ati venit!" << endl;
}

void Client::load(char *continut)
{
	char *p = strtok(continut," \n\0");
	for( int i = 0; i < 11 ; i++ )
	{
		if ( i == 0 )
			this->setTip(p);
		if ( i == 1 )
			this->setUsername(p);
		if ( i == 2 )
			this->setPassword(p);
		if ( i == 3 )
			this->setQuestion(p);
		if ( i == 4 )
			this->setAnswer(p);
		if ( i == 5 )
			this->_mAdresaClient->setTara(p);
		if ( i == 6 )
			this->_mAdresaClient->setLocalitate(p);
		if ( i == 9 )
			this->setEmail(p);
		if (i == 10)
			this->setTelefon(p);
		p = strtok(NULL," \n\0");
	}
	
}

Admin* Admin::_mInstance = NULL;

Admin* Admin::getInstance(char *tip)
{
	if (_mInstance == NULL )
	{
		_mInstance = new Admin(tip);
		CHECK_ALLOC(_mInstance);
	}
	return _mInstance;
}

Admin::Admin():_CUser()
{
	setTip("Admin");
}

Admin::Admin(char *tip):_CUser()
{
	setTip(tip);
	this->Register();
}

Admin::~Admin(){}

void Admin::DestroyInstance()
{
	if (_mInstance == NULL )
		return;
	delete _mInstance;
	_mInstance = NULL;
}

void Admin::Register()
{
	char *username = new char[256];
	cout << endl << "\tNume utilizator:" << endl;
	cin >> username;
	setUsername(username);
	delete[] username;

	char* password = new char[256];
	cout << endl << "\tParola:" << endl;
	CString pass = "";
	char ch;
	ch = _getch();
	while(ch!=13){
	pass = pass + ch;
	cout << '*';
	ch = _getch();
	}
	strcpy(password,pass.get_data());
	setPassword(password);
	delete[] password;

	char* question = new char[256];
	cout << endl << "\tIntrebarea de securitate:" << endl;
	cin >> question;
	setQuestion(question);
	delete[] question;

	char* answer = new char[256];
	cout << endl << "\tRaspunsul la intrebarea de securitate: " << endl;
	cin >> answer;
	setAnswer(answer);
	delete[] answer;
	cout << endl << "\t\tBine ati venit!" << endl;
}