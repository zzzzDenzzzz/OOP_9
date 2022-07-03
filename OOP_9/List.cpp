#include "List.h"

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	DelAll();
}
int List::GetCount()
{
	return Count;
}
void List::Add(string number_auto, string name_fine, int price)
{
	Element *temp = new Element;
	temp->f = Fine(number_auto, name_fine, price);
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}
}
void List::Del()
{
	Element *temp = Head;
	Head = Head->Next;
	delete temp;
}
void List::DelAll()
{
	while (Head != 0)
		Del();
}
void List::Print()
{
	Element *temp = Head;
	while (temp != 0)
	{
		cout << temp->f.number_auto << " " << temp->f.name_fine << " " << temp->f.price << "\n";
		temp = temp->Next;
	}
	cout << "\n\n";
}