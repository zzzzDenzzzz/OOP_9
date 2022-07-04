#pragma once

#include<iostream>
#include<string>
#include"Fine.h"

using namespace std;

struct Element
{
	Fine f;
	Element *next;
};

class List
{
	Element *head;
	Element *tail;
	int count;
public:
	List();
	~List();
	void add(string number_auto, string name_fine, int price);
	void del();
	void delAll();
	void print();
	int getCount();
};