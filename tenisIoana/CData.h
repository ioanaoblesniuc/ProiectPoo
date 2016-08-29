class CData
{
	int _mZi;
	int _mLuna;
	int _mAn;
public:
	CData();
	CData(int,int,int);
	CData(CData& data);

	void setData(int,int,int);
	CData& getData() const;
	int getZi() const;
	int getLuna() const;
	int getAn() const;
	
	void printData();

	bool operator==(CData& X);
	void operator=(CData& X);
	bool operator<(CData& X);
	bool operator>(CData& X);

	~CData(){}

};