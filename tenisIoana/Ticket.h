#pragma once
#include "_CUser.h"
#include "Game.h"
#include "Features.h"
class Ticket
{
protected:
	float price;
	_CUser * user;
	const float price_First_Tour = 50;
	const float percentIncrement = 0.2;
public:
	virtual bool getPrice()const  = 0;
	virtual void PrintPacket()=0;
	virtual int displayDiscount() = 0;
};

class SimpleTicket : public Ticket 
{
private:
	Game game;
public :
	SimpleTicket(_CUser * user,const Game& rhs)
	{
		this->game = game;
		this->user = user;

		//this->price = price_First_Tour + percentIncrement * game.
	}
	virtual bool getPrice()
	{
		return price;
	}
};

class ComplexTicket : public Ticket 
{
private:
	std::list<SimpleTicket> tickets;
	int discount;
public :
	ComplexTicket(_CUser * user,const std::list<SimpleTicket>& ticket)
	{
		this->user = user;
		this->tickets = ticket;
		discount = 0;
		if(ticket.size() == 2)
			discount = 0.05;
		if(ticket.size() == 3)
			discount = 0.1;
		float sum = 0;
		for ( auto it = tickets.begin() ; it != tickets.end();it++)
		{
			sum += (*it).getPrice();
		}
		this->price  = sum - sum*discount;
	}
};

class AllInclusiveTicket : public Ticket 
{
private:
	ComplexTicket ticket;

	list<Feature> features;
	int discount;
	AllInclusiveTicket(const ComplexTicket&);
	void addFeature(Feature feature);
	int getFinalPrice();
public :
};

