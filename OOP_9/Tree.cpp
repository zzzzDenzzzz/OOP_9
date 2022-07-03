#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}
//����������� ����� ������
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
	//���� ���� ���� � ����� �� ���������
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
	//����� ������ "������" ����
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
		//���� ���� ������ �������
		if (Node->right != 0)
			return Min(Node->right);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && Node == y->right)
		{
			//�������� �����
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
	//�������� ���
	z->left = NULL;
	z->right = NULL;
	Elem *y = NULL;
	Elem *Node = root;
	//����� �����
	while (Node != 0)
	{
		//������� ��������
		y = Node;
		if (z->key > Node->key)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//��������� ��������
	z->parent = y;
	if (y == 0) //������� ������ (������������)
		root = z;
	//��� ���� ������?
	else if (z->key > Node->key)
		y->left = z;
	else
		y->right = z;
}
void Tree::Del(Elem *z)
{
	//�������� �����
	if (z != 0)
	{
		Elem *Node, *y;
		//�� 2 �������
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
		//��������� �������� ����?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = Node;
		else
			//������ �� ��������?
			y->parent->right = Node;
		if (y != z)
		{
			//����������� ������ ����
			z->key = y->key;
			z->list = y->list;
		}
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}