#include "CString.h"
#include "CExceptie.h"
#include "CStrada.h"

//modificare 

class CAdresa
{
	CString* _mTara;
	CString* _mLocalitate;
	CStrada* _mStrada;
public:
	CAdresa();
	CAdresa(char*,char*,char*,int);

	void setTara(char*);
	void setLocalitate(char*);
	void setStrada(char*,int);

	CString& getTara() const;
	CString& getLocalitate() const;
	CStrada& getStrada() const;

	~CAdresa();
};