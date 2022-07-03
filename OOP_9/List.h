#pragma once

#include<iostream>
#include<string>
#include"Fine.h"

using namespace std;

struct Element
{
	Fine f;
	Element *Next;
};

class List
{
	Element *Head;
	Element *Tail;
	int Count;
public:
	List();
	~List();
	void Add(string number_auto, string name_fine, int price);
	void Del();
	void DelAll();
	void Print();
	int GetCount();
};