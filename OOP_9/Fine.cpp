#include "Fine.h"

Fine::Fine()
{
	number_auto = "";
	name_fine = "";
	price = 0;
}

Fine::Fine(string number_auto, string name_fine, int price)
{
	this->number_auto = number_auto;
	this->name_fine = name_fine;
	this->price = price;
}

string Fine::getNumberAuto()
{
	return number_auto;
}

string Fine::getNameFine()
{
	return name_fine;
}

int Fine::getPrice()
{
	return price;
}
