#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}
//Рекурсивный обход дерева
void Tree::Print(Elem *Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		Node->list.Print();
		Print(Node->right);
	}
}
Tree::Elem *Tree::Search(Elem *Node, string k)
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
Tree::Elem *Tree::Min(Elem *Node)
{
	//Поиск самого "левого" узла
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
Tree::Elem *Tree::Next(Elem *Node)
{
	Elem *y = 0;
	if (Node != 0)
	{
		//если есть правый потомок
		if (Node->right != 0)
			return Min(Node->right);
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

Tree::Elem *Tree::GetRoot()
{
	return root;
}
void Tree::Insert(Elem *z)
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
void Tree::Del(Elem *z)
{
	//удаление куста
	if (z != 0)
	{
		Elem *Node, *y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
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
			Del(root);
}