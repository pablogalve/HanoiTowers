#include "rod.h"
#include <chrono>
#include <thread>

void towerOfHanoi(int n, rod *from_rod, rod *to_rod, rod *aux, int *moves, int level, rod rod1, rod rod2, rod rod3) {
	

	if (n == 1) {
		from_rod->moveElement(to_rod);
		//Print result
		(int)moves++;
		system("cls");
		cout << "LEVEL: " << level << endl;
		cout << "DISKS: " << level + 2 << endl;
		cout << "MOVES: " << (int)moves << endl << endl;
		rod1.printList();
		rod2.printList();
		rod3.printList();
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux, to_rod, moves, level, rod1, rod2, rod3);
	from_rod->moveElement(to_rod);
	//Print result
	(int)moves++;
	system("cls");
	cout << "LEVEL: " << level << endl;
	cout << "DISKS: " << level + 2 << endl;
	cout << "MOVES: " << (int)moves << endl << endl;
	rod1.printList();
	rod2.printList();
	rod3.printList();
	towerOfHanoi(n - 1, aux, to_rod, from_rod, moves, level, rod1, rod2, rod3);
}

int main() {
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	rod rod1;
	rod rod2;
	rod rod3;
	rod1.name = "Rod1";
	rod2.name = "Rod2";
	rod3.name = "Rod3";

	int level = 1; //Disks = level + 2
	int moves = 0;
	int player;

	bool solved = false; //It indicates if all elements have been moved from origin to destination

	int from, to;
	rod *from_rod, *to_rod;

	from = to = 0;
	from_rod = to_rod = nullptr;
	
	cout << "Who will solve the puzzle? Write the number" << endl<< "1. Me" << endl << "2. Artificial Intelligence" << endl;
	cin >> player;
	system("cls");

	do {
		cout << "----- Level " << level << " started! -----" << endl;
		cout << "----- Good luck! -----" << endl;
		moves = 0;
		//We add disks to first row
		//Disks added = Level + 2
		for (int i = level+2; i > 0; i--) {
			rod1.addElement(i);
		}

		rod1.printList();
		rod2.printList();
		rod3.printList();
		do {	
			if (player == 1) { //Solved by human
				cout << "Choose rod '1,2 or 3'." << endl;
				cout << "FROM: ";
				cin >> from;
				cout << "TO: ";
				cin >> to;

				if (from == 1) from_rod = &rod1; //Origin rod
				else if (from == 2) from_rod = &rod2;
				else if (from == 3) from_rod = &rod3;
				else from_rod = 0;

				if (to == 1) to_rod = &rod1;  //Destination rod
				else if (to == 2) to_rod = &rod2;
				else if (to == 3) to_rod = &rod3;
				else to_rod = 0;

				switch (from) {
				case 1:
					rod1.moveElement(to_rod);
					break;
				case 2:
					rod2.moveElement(to_rod);
					break;
				case 3:
					rod3.moveElement(to_rod);
					break;
				default:
					cout << "Your 'from' is incorrect." << endl << "Please try again with 1, 2 or 3" << endl;
					cout << "It will refresh in 5 seconds...";
					sleep_until(system_clock::now() + seconds(5));
					break;
				}
				moves++;
				system("cls");
				cout << "LEVEL: " << level << endl;
				cout << "DISKS: " << level + 2 << endl;
				cout << "MOVES: " << moves << endl << endl;
				rod1.printList();
				rod2.printList();
				rod3.printList();
			}
			else if (player == 2) { //Solved by AI
				towerOfHanoi(level + 2, &rod1, &rod3, &rod2, &moves, level, rod1, rod2, rod3);
				system("pause");
			}			

			//It is solved if rods 1 and 2 are empty and 3 is not empty
			if (rod1.checkEmpty())
				if (rod2.checkEmpty())
					if(rod3.checkEmpty() == false)
						solved = true;
		} while (!solved);
		system("cls");
		cout << "Congratulations! " << endl << "You finished level: " << level << endl;
		level++;

		//We remove all elements before starting next level
		while (rod1.checkEmpty() == false)
			rod1.deleteElement();
		while (rod2.checkEmpty() == false)
			rod2.deleteElement();
		while (rod3.checkEmpty() == false)
			rod3.deleteElement();
	} while (level < 100);	

	system("pause");
	return 0;
}