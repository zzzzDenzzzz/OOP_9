#include"List.h"
#include"Tree.h"

int main()
{
	Tree tree;
	List lst;
	lst.Add("A777AA", "speed", 500);
    lst.Add("B888AA", "speed", 1000);
	Tree::Elem *el;
	el = new Tree::Elem;
	el->list = lst;
	tree.Insert(el);
	tree.Print(el);

	return 0;
}