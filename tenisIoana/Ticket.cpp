#pragma once
#include "ticket.h"

SimpleTicket::SimpleTicket(_CUser * user, const Game& rhs)
{
	this->game = game;
	this->user = user;
	this->price = price_First_Tour + percentIncrement * game.getLevel();
}

float SimpleTicket::getPrice()
{
	return price;
}

float SimpleTicket::displayDiscount()
{
	return 0.0;
}

std::string SimpleTicket::toString()
{
	string str;
	str.append("Ticket Simplu");

	return str;
}

SimpleTicket::SimpleTicket(const SimpleTicket& rhs)
{
	this->game = (Game)rhs.game;
	this->price = rhs.price;
}

ComplexTicket::ComplexTicket(_CUser * user, const std::list<SimpleTicket>& ticket)
{
	this->user = user;
	this->tickets = ticket;
	discount = 0;
	if (ticket.size() == 2)
		discount = 0.05f;
	if (ticket.size() == 3)
		discount = 0.1f;
	float sum = 0;
	for (auto it = tickets.begin(); it != tickets.end(); it++)
	{
		sum += (*it).getPrice();
	}
	this->price = sum - sum*discount;
}
ComplexTicket::ComplexTicket()
{

}

float ComplexTicket::getPrice()
{
	return price;
}

float ComplexTicket::displayDiscount()
{
	return 0.0;
}

std::string ComplexTicket::toString()
{
	string str;
	str.append("Ticket Complex");

	return str;
}