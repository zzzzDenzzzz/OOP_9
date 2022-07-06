#include "List.h"

List::List()
{
	head = tail = NULL;
}
List::~List()
{
	delAll();
}

Element *List::getElement()
{
	return &element;
}
void List::add(const string number_auto, const string name_fine, const string price)
{
	Element *temp = new Element;
	temp->f = Fine(number_auto, name_fine, price);
	element.f = temp->f;
	temp->next = nullptr;
	if (head != nullptr) {
		tail->next = temp;
		tail = temp;
	}
	else 
	{
		head = tail = temp;
	}
}
void List::del()
{
	Element *temp = head;
	head = head->next;
	delete temp;
}
void List::delAll()
{
	while (head != nullptr)
		del();
}
void List::print()
{
	Element *temp = head;
	while (temp != nullptr)
	{
		cout << temp->f.number_auto << " " << temp->f.name_fine << " " << temp->f.price << "\n";
		temp = temp->next;
	}
}