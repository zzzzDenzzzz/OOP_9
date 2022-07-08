#pragma once

#include<iostream>
#include<string>
#include"Fine.h"

using namespace std;

struct Node
{
	Fine fine;
	Node *next;
};

class List
{
	Node *node;
	Node *first;
	Node *last;
public:
	List();
	bool isEmpty();
	void pushBack(Fine &fine);
	void removeFirstNode();
	void removeLastNode();
	void print();
	Node *getNode();
};