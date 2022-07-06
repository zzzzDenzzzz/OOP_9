#pragma once
 
#include"List.h"

using namespace std;

//struct TreeElement
//{
//	string key;
//	List list;
//	TreeElement *left; 
//	TreeElement *right;
//	TreeElement *parent;
//};

class Tree
{
	//TreeElement *root_tree;
public:
	struct TreeElement
	{
		string key;
		List list;
		TreeElement *left;
		TreeElement *right;
		TreeElement *parent;
	};
	TreeElement *root_tree;
	Tree();
	~Tree();
	TreeElement *next(TreeElement *node);
	TreeElement *min(TreeElement *node);
	void del(TreeElement *element = nullptr);
	void print(TreeElement *node);
	TreeElement *search(TreeElement *node, string key);
	void insert(TreeElement *element);
	TreeElement *getRoot();
	//void add(List &list);
};