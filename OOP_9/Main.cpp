#include"List.h"
#include"Fine.h"
#include"Tree.h"

int main()
{
	Fine fine_1("SPEED", "500");
	Fine fine_2("SPEED", "1000");
	Fine fine_3("SPEED", "1500");
	Fine fine_4("SPEED", "2000");
	Fine fine_5("SPEED", "2500");

	List list_1;
	list_1.pushBack(fine_1);
	list_1.pushBack(fine_2);
	list_1.pushBack(fine_3);
	list_1.pushBack(fine_4);
	List list_2;
	list_2.pushBack(fine_2);
	list_2.pushBack(fine_3);
	list_2.pushBack(fine_4);
	List list_3;
	list_3.pushBack(fine_3);
	list_3.pushBack(fine_4);
	List list_4;
	list_4.pushBack(fine_5);

	Tree tree;
	tree.add(list_1, "D999DD");
	tree.add(list_2, "B777BB");
	tree.add(list_3, "E555EE");
	//tree.add(list_4, "A333AA");
	tree.print();
	tree.print("B777BB");
	tree.print("A777BB");
	
	return 0;
}