#include "Fine.h"

Fine::Fine()
{
	number_auto = "OOO";
	name_fine = "X";
	price = "0";
}

Fine::Fine(const string number_auto, const string name_fine, const string price)
{
	this->number_auto = number_auto;
	this->name_fine = name_fine;
	this->price = price;
}