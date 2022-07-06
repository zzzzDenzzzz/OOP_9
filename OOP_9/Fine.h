#pragma once

#include<string>

using namespace std;

class Fine
{
public:
	string number_auto;
	string name_fine;
	string price;
	Fine();
	Fine(const string number_auto, const string name_fine, const string price);
};