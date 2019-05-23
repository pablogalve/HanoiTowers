#include "rod.h"

int main() {
	rod rod1;
	rod rod2;
	rod rod3;

	rod1.addElement(1);
	rod1.addElement(2);
	rod1.addElement(3);
	rod2.addElement(4);
	rod3.addElement(5);

	int from;
	int to;
	cout << "Change element from rod: ";
	cin >> from;
	cout << "Change element to rod: ";
	cin >> to;


	rod1.printList();
	rod2.printList();
	rod3.printList();


	system("pause");
	return 0;
}