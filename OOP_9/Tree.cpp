#include "Tree.h"

Tree::Tree()
{
	root_tree = nullptr;
}

Tree::~Tree()
{
	//del();
}

Tree::TreeElement *Tree::next(TreeElement *node)
{
	TreeElement *tmp = nullptr;

	if (node != nullptr)
	{
		if (node->right != nullptr)
		{
			return min(node->right);
		}

		tmp = node->parent;
		while (tmp != nullptr and node == tmp->right)
		{
			node = tmp;
			tmp = tmp->parent;
		}
	}
	return tmp;
}

Tree::TreeElement *Tree::min(TreeElement *node)
{
	if (node != nullptr)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
	}
	return node;
}

void Tree::del(TreeElement *element)
{
	if (element != nullptr)
	{
		TreeElement *node;
		TreeElement *tmp;

		if (element->left == nullptr or element->right == nullptr)
		{
			tmp = element;
		}
		else
		{
			tmp = next(element);
		}

		if (tmp->left != nullptr)
		{
			node = tmp->left;
		}
		else
		{
			node = tmp->right;
		}

		if (node != nullptr)
		{
			node->parent = tmp->parent;
		}

		if (tmp->parent == nullptr)
		{
			root_tree = node;
		}
		else if (tmp == tmp->parent->left)
		{
			tmp->parent->left = node;
		}
		else
		{
			tmp->parent->right = node;
		}

		if (tmp != element)
		{
			element->list.getElement()->f.name_fine = tmp->list.getElement()->f.name_fine;
			element->list.getElement()->f.number_auto = tmp->list.getElement()->f.number_auto;
			element->list.getElement()->f.price = tmp->list.getElement()->f.price;
		}
		delete tmp;
	}
	else
	{
		while (root_tree != nullptr)
		{
			del(root_tree);
		}
	}
}

void Tree::print(TreeElement *node)
{
	if (node != nullptr)
	{
		print(node->left);
		cout<<node->list.getElement()->f.number_auto << " ";
		cout << node->list.getElement()->f.name_fine << " ";
		cout << node->list.getElement()->f.price << endl;
		print(node->right);
	}
}

Tree::TreeElement *Tree::search(TreeElement *node, string key)
{
	while (node != nullptr and key != node->list.getElement()->f.number_auto)
	{
		if (node->list.getElement()->f.number_auto < key)
		{
			cout << "Left\n";
			node = node->left;
			node->list.print();
		}
		else
		{
			cout << "Right\n";
			node = node->right;
			node->list.print();
		}
	}
	return node;
}

void Tree::insert(TreeElement *element)
{
	element->left = nullptr;
	element->right = nullptr;

	TreeElement *tmp = nullptr;
	TreeElement *node = root_tree;

	while (node != nullptr)
	{
		tmp = node;
		if (element->list.getElement()->f.number_auto < node->list.getElement()->f.number_auto)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	element->parent = tmp;
	if (tmp == nullptr)
	{
		root_tree = element;
	}
	else if (element->list.getElement()->f.number_auto < tmp->list.getElement()->f.number_auto)
	{
		tmp->left = element;
	}
	else
	{
		tmp->right = element;
	}
}

Tree::TreeElement *Tree::getRoot()
{
	return root_tree;
}
//
//void Tree::add(List &list)
//{
//	Tree tree;
//	if (root_tree == nullptr)
//	{
//		root_tree = new TreeElement;
//		root_tree->list = list;
//		insert(root_tree);
//	}
//	else
//	{
//		root_tree->left = new TreeElement;
//		root_tree->right = new TreeElement;
//	}
//}
