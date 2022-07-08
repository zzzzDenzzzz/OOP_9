#pragma once

#include<string>

using namespace std;

class Fine
{
public:
	string name_fine;
	string price;
	Fine();
	Fine(const string &name_fine, const string &price);
};