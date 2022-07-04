#include "List.h"

List::List()
{
	head = tail = NULL;
	count = 0;
}
List::~List()
{
	delAll();
}
int List::getCount()
{
	return count;
}
void List::add(string number_auto, string name_fine, int price)
{
	Element *temp = new Element;
	temp->f = Fine(number_auto, name_fine, price);
	temp->next = NULL;
	if (head != NULL) {
		tail->next = temp;
		tail = temp;
	}
	else {
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
	while (head != 0)
		del();
}
void List::print()
{
	Element *temp = head;
	while (temp != 0)
	{
		cout << temp->f.getNumberAuto() << " " << temp->f.getNameFine() << " " << temp->f.getPrice() << "\n";
		temp = temp->next;
	}
	cout << "\n\n";
}