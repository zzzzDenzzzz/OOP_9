#pragma once
 
#include"List.h"

using namespace std;

struct TreeNode
{
	List list;
	string number_auto;
	TreeNode *left; 
	TreeNode *right;
};

class Tree
{
	TreeNode *root;
public:
	Tree();
	void insert(TreeNode *&tree_node, List &list);
	void add(List &list, const string &number);
	void print(const string &number);
	void print();
};