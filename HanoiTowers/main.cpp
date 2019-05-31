#include "rod.h"
//#include "Stack.h"

int main() {
	rod rod1;
	rod rod2;
	rod rod3;

	bool moved;
	bool solved = false; //It indicates if all elements have been moved from origin to destination

	int from, to;
	rod *from_rod, *to_rod;

	from = to = 0;
	from_rod = to_rod = nullptr;

	rod1.addElement(5);
	rod1.addElement(4);
	rod1.addElement(3);
	rod2.addElement(6);
	rod3.addElement(7);
	rod3.addElement(6);

	rod1.printList();
	rod2.printList();
	rod3.printList();

	rod1.moveElement(rod2);
	rod1.printList();
	rod2.printList();
	rod3.printList();
	
	cout << "Choose rod '1,2 or 3'." << endl;
	cout << "Change element from rod: ";
	cin >> from;
	cout << "Change element to rod: ";
	cin >> to;

	if (from == 1) from_rod = &rod1; //Origin rod
	else if (from == 2) from_rod = &rod2;
	else if (from == 3) from_rod = &rod3;
	else from_rod = 0;
	
	if (to == 1) to_rod = &rod1;  //Destination rod
	else if (to == 2) to_rod = &rod2;
	else if (to == 3) to_rod = &rod3;
	else to_rod = 0;

	if (from != 0 && to != 0 && from != to) {
		//moved = from_rod->moveElement(to_rod);
	}

	rod1.printList();
	rod2.printList();
	rod3.printList();


	system("pause");
	return 0;
}