#pragma once

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include"List.h"

using namespace std;

//struct Elem
//{
//	string key;
//	List list;
//	Elem *left, *right, *parent;
//};
class Tree
{
public:
	struct Elem
	{
		string key;
		List list;
		Elem *left, *right, *parent;
	};
	Elem *root;
	Tree();
	~Tree();
	void Print(Elem *Node);
	Elem *Search(Elem *Node, string key);
	Elem *Min(Elem *Node);
	Elem *Next(Elem *Node);
	void Insert(Elem *z);
	void Del(Elem *z = 0);
	Elem *GetRoot();
};