#include "List.h"

List::List()
{
	node = nullptr;
	first = nullptr;
	last = nullptr;
}

bool List::isEmpty()
{
	return first == nullptr;
}

void List::pushBack(Fine &fine)
{
	Node *node = new Node;
	node->fine = fine;
	node->next = nullptr;
	if (isEmpty())
	{
		first = node;
		last = node;
		return;
	}
	last->next = node;
	last = node;
}

void List::removeFirstNode()
{
	if (isEmpty())
	{
		return;
	}
	Node *node = first;
	first = node->next;
	delete node;
}

void List::removeLastNode()
{
	if (isEmpty())
	{
		return;
	}
	if (first == last)
	{
		removeFirstNode();
		return;
	}
	Node *node = first;
	while (node->next != last)
	{
		node = node->next;
	}
	node->next = nullptr;
	delete last;
	last = node;
}

void List::print()
{
	if (isEmpty())
	{
		return;
	}
	Node *node = first;
	while (node)
	{
		cout << node->fine.name_fine << " " << node->fine.price << endl;
		node = node->next;
	}
	cout << endl;
}

Node *List::getNode()
{
	return node;
}
