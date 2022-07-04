#pragma once

#include<string>

using namespace std;

class Fine
{
	string number_auto;
	string name_fine;
	int price;
public:
	Fine();
	Fine(string number_auto, string name_fine, int price);
	string getNumberAuto();
	string getNameFine();
	int getPrice();
};