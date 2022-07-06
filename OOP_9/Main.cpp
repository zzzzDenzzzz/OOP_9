#include"List.h"
#include"Tree.h"

int main()
{
	
	List lst_1, lst_2, lst_3, lst_4;
	lst_1.add("D777DD", "speed limit", "500");
	lst_2.add("B666BB", "speed limit", "1500");
	lst_3.add("C555CC", "speed limit", "1000");
	lst_4.add("A333KK", "speed limit", "250");

	Tree tree;
	Tree::TreeElement *l = new Tree::TreeElement;
	l->list = lst_1;
	tree.insert(l);
	Tree::TreeElement *ll = new Tree::TreeElement;
	ll->list = lst_2;
	tree.insert(ll);
	Tree::TreeElement *lll = new Tree::TreeElement;
	lll->list = lst_3;
	tree.insert(lll);
	Tree::TreeElement *llll = new Tree::TreeElement;
	llll->list = lst_4;
	tree.insert(llll);
	tree.print(l);

	return 0;
}