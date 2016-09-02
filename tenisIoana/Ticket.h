#pragma once
#include "_CUser.h"
#include "Game.h"
#include "Features.h"
class Ticket
{
protected:
	float price;
	_CUser * user;
	const float price_First_Tour = 50.0f;
	const float percentIncrement = 0.2f;
public:
	virtual float getPrice() = 0;
	virtual std::string toString()=0;
	virtual float displayDiscount() = 0;
};

class SimpleTicket : public Ticket 
{
private:
	Game game;
public :
	SimpleTicket(_CUser * user, const Game& rhs);
	SimpleTicket(const SimpleTicket&);
	float getPrice();
	float displayDiscount();
	std::string toString();
};

class ComplexTicket : public Ticket 
{
private:
	std::list<SimpleTicket> tickets;
	float discount;
public :
	ComplexTicket(_CUser * user, const std::list<SimpleTicket>& ticket);
	ComplexTicket();
	float getPrice();
	float displayDiscount();
	std::string toString();
};

class AllInclusiveTicket : public Ticket 
{
private:
	ComplexTicket ticket;
	list<Feature> features;
	float discount;
	void addFeature(Feature feature);
	int getFinalPrice();
public :
	AllInclusiveTicket(const ComplexTicket&);
	float getPrice();
	float displayDiscount();
	std::string toString();
};

