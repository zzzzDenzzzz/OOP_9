#include"List.h"
#include"Tree.h"

int main()
{
	Tree tree;
	List lst;
	Tree::Elem *el = NULL;
	lst.add("A777AA", "speed", 500);
    lst.add("B888AA", "speed", 1000);
	tree.add(777, lst, el);
	tree.print(el);

	return 0;
}