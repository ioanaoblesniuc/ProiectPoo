//#pragma once
//#include<string>
//#include<list>
//#include "_CUser.h"
//#include<map>
//#include "CData.h"
//#include "Ora.h"
//using namespace std;
//
//class Place
//{
//	int sector;
//	int number;
//	bool busy;
//public:
//	void print();
//};
//
//class TenisCourt
//{
//	string name;
//	int Capacity;
//	list<Place> places;
//public:
//	bool isEmpty(int,int);
//	void markBusy(int,int);
//};
//
//class Score
//{
//};
//
//class Player
//{
//	int TournementRank;
//	int GlobalRank;
//	string name;
//
//};
//
//enum Type
//{
//	SingleMasculin,
//	SingleFeminin,
//	DoubleFeminin,
//	DoubleMasculin,
//	Mixed
//};
//
//class Game
//{
//	list<Player> team1;
//	list<Player> team2;
//	TenisCourt arena;
//	int level;//round1,2,..7
//	Score scores;
//	bool isLive;
//	COra ora;
//	CData data;
//public:
//	void print();
//	bool isStarted();
//	bool isFinished();
//};
//
//class Tournement
//{
//	list<Game> games;//1,2,3,.. group 2 by 2
//public:
//	void printDetails();
//	void start();
//	Tournement();
//	~Tournement();
//};
//	
//class Packet{
//public:
//	virtual void Booking() = 0;
//	virtual bool getPrice() = 0;
//	virtual void PrintPacket() = 0;
//	virtual int displayDiscount() = 0;
//};