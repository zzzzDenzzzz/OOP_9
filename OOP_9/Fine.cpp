#include "Fine.h"

Fine::Fine()
{
	name_fine = "NO_NAME";
	price = "0";
}

Fine::Fine(const string &name_fine, const string &price)
{
	this->name_fine = name_fine;
	this->price = price;
}