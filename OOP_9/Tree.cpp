#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	del();
}
//����������� ����� ������
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
Tree::Elem *Tree::min(Elem *Node)
{
	//����� ������ "������" ����
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
		//���� ���� ������ �������
		if (Node->right != 0)
			return min(Node->right);
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
void Tree::del(Elem *z)
{
	//�������� �����
	if (z != 0)
	{
		Elem *Node, *y;
		//�� 2 �������
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
			del(root);
}