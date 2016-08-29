class COra
{
	int _mOra;
	int _Min;
public:
	COra();
	COra(int,int);
	COra(COra& ora);

	void setOra(int,int);
	COra& getOra() const;
	int _getOra() const;
	int getMin()const;

	void printOra();

	bool operator==(COra& X);
	void operator=(COra& X);

	~COra(){}
};