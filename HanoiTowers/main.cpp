#include "rod.h"

int main() {
	rod rod1;
	rod rod2;
	rod rod3;

	rod1.addElement(20);
	rod1.addElement(19);
	rod1.addElement(18);
	rod2.addElement(21);
	rod3.addElement(22);

	rod1.printList();
	rod2.printList();
	rod3.printList();

	rod1.moveElement(rod2);
	rod1.printList();
	rod2.printList();
	rod3.printList();

	int from;
	int to;
	cout << "Choose rod '1,2 or 3'." << endl;
	cout << "Change element from rod: ";
	cin >> from;
	cout << "Change element to rod: ";
	cin >> to;

	if (from == 1) {
		switch (to) {
		case 1:
			rod1.moveElement(rod1);
			break;
		case 2:
			rod1.moveElement(rod2);
			break;
		case 3:
			rod1.moveElement(rod3);
			break;
		default:
			cout << "Incorrect 'to_rod'. Please try again" << endl;
			break;
		}
		
	}
	else if (from == 2) {

	}
	else if (from == 3) {

	}
	else {
		cout << "Incorrect 'from_rod'. Please try again" << endl;
	}
	

	rod1.printList();
	rod2.printList();
	rod3.printList();


	system("pause");
	return 0;
}