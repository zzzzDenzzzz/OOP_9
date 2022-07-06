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
	Element element;
	Element *head;
	Element *tail;
public:
	List();
	~List();
	void add(const string number_auto, const string name_fine, const string price);
	void del();
	void delAll();
	void print();
	Element *getElement();
};