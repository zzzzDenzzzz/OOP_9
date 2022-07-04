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
		int key;
		List list;
		Elem *left, *right, *parent;
	};
	Elem *root;
	Tree();
	~Tree();
	void print(Elem *Node);
	Elem *search(Elem *Node, int key);
	Elem *min(Elem *Node);
	Elem *next(Elem *Node);
	void insert(Elem *z);
	void del(Elem *z = 0);
	Elem *getRoot();
	void add(int key, List list, Elem *&elem);
};