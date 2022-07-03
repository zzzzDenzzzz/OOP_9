#pragma once

#include<string>

using namespace std;

class Fine
{
public:
	string number_auto;
	string name_fine;
	int price;
	Fine();
	Fine(string number_auto, string name_fine, int price);
};