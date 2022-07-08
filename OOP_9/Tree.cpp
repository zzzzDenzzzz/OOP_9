#include "Tree.h"

Tree::Tree()
{
	root = nullptr;
}

void Tree::insert(TreeNode *&tree_node, List &list)
{
	if (tree_node == nullptr)
	{
		tree_node = new TreeNode;
		tree_node->list = list;
		tree_node->left = nullptr;
		tree_node->right = nullptr;
	}
}

void Tree::add(List &list, const string &number)
{
	TreeNode *tmp = nullptr;
	if (root == nullptr)
	{
		insert(root, list);
		root->number_auto = number;
	}
	else if (number < root->number_auto)
	{
		//tmp = root;
		//while (root != nullptr)
		//{
		//	root = root->left;
		//}
		insert(root->left, list);
		//root = tmp;
		root->left->number_auto = number;
	}
	else if (number > root->number_auto)
	{
		//tmp = root;
		//while (root != nullptr)
		//{
		//	root = root->right;
		//}
		insert(root->right, list);
		//root = tmp;
		root->right->number_auto = number;

	}
	else
	{
		cout << "ERROR!!!\n";
	}
}

void Tree::print(const string &number)
{
	TreeNode *tmp = root;
	if (root == nullptr)
	{
		cout << "Is empty!!!\n";
	}
	else
	{
		if (number < root->number_auto)
		{
			tmp = tmp->left;
		}
		if (number > root->number_auto)
		{
			tmp = tmp->right;
		}
		if (number == tmp->number_auto)
		{
			cout << number << ": \n";
			tmp->list.print();
		}
		else
		{
			cout << "Not found!!!\n";
		}
	}
}

void Tree::print()
{
	if (root == nullptr)
	{
		return;
	}
	TreeNode *tmp = root;
	while (tmp != nullptr)
	{
		cout << tmp->number_auto << ": \n";
		tmp->list.print();
		tmp = tmp->left;
	}
	tmp = root->right;
	while (tmp != nullptr)
	{
		cout << tmp->number_auto << ": \n";
		tmp->list.print();
		tmp = tmp->right;
	}
}
