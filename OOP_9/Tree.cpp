#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	del();
}
//Рекурсивный обход дерева
void Tree::print(Elem *Node)
{
	if (Node != 0)
	{
		print(Node->left);
		Node->list.print();
		print(Node->right);
	}
}
Tree::Elem *Tree::search(Elem *Node, int k)
{
	//Пока есть узлы и ключи не совпадают
	while (Node != 0 && k == Node->key)
	{
		if (Node->key < k)
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}
Tree::Elem *Tree::min(Elem *Node)
{
	//Поиск самого "левого" узла
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
Tree::Elem *Tree::next(Elem *Node)
{
	Elem *y = 0;
	if (Node != 0)
	{
		//если есть правый потомок
		if (Node->right != 0)
			return min(Node->right);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node справа
		while (y != 0 && Node == y->right)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

Tree::Elem *Tree::getRoot()
{
	return root;
}
void Tree::add(int key, List list, Elem *&elem)
{
	if (elem == NULL)
	{
		elem = new Elem;
		elem->key = key;
		elem->list = list;
		elem->left = nullptr;
		elem->right = nullptr;
		elem->parent = nullptr;
		return;
	}
	if (key > elem->key)
	{
		add(key, list, elem->right);
	}
	else
	{
		add(key, list, elem->left);
	}
}
void Tree::insert(Elem *z)
{
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	Elem *y = NULL;
	Elem *Node = root;
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (z->key > Node->key)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//заполняем родителя
	z->parent = y;
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else if (z->key > Node->key)
		y->left = z;
	else
		y->right = z;
}
void Tree::del(Elem *z)
{
	//удаление куста
	if (z != 0)
	{
		Elem *Node, *y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//Удаляется корневой узел?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//слева от родителя?
			y->parent->left = Node;
		else
			//справа от родителя?
			y->parent->right = Node;
		if (y != z)
		{
			//Копирование данных узла
			z->key = y->key;
			z->list = y->list;
		}
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			del(root);
}