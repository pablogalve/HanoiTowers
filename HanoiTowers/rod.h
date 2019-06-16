#ifndef _ROD_H
#define _ROD_H
#include <iostream>
#include <string>
using namespace std;

#define MAX_ELEMENTS 6
class rod {
public:
	int elements[MAX_ELEMENTS]; //list of elements
	string name; //rod's name

	rod();
	~rod();
	bool addElement(int elem); //adds element and returns true if it was added. False if it was not added
	void deleteElement();
	void moveElement(rod *to_rod);
	int getLastElement();
	void printList();
	bool checkEmpty(); //return true if it is empty
	//void towerOfHanoi(int n, rod *from_rod, rod *to_rod, rod *aux); //solves the puzzle by recursivity
};
#endif // !_ROD_H

rod::rod() {
	name = "";
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		elements[i] = NULL;
	}
}
rod::~rod() {}

bool rod::addElement(int elem) {

	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[0] == NULL)
		{
			elements[i] = elem; //we add the element
			return true;
		}
		else if (elements[i] == NULL)
		{
			if (elements[i - 1] >= elem) {
				elements[i] = elem; //we add the element
				return true;
			}
			else {
				cout << "Error: Your element is smaller." << endl;
				return false;
			}
		}
	}
}
void rod::deleteElement() {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[i] != NULL && elements[i + 1] == NULL) {
			elements[i] = NULL;
			break;
		}
	}
}
int rod::getLastElement() {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[i] == NULL)
		{
			if (i != 0) {
				return elements[i - 1];
			}
			else
			{
				cout << "This rod is empty" << endl;
				return elements[i];
			}
		}
	}
	return 0;
}
void rod::moveElement(rod *to_rod) {
	int elem = getLastElement();
	if (to_rod->addElement(elem))
		this->deleteElement(); //It only deletes the element if it was added successfully to the other rod
}
void rod::printList() {
	cout << name << ": " << endl;
	for (int i = MAX_ELEMENTS - 1; i >= 0; i--) {

		if (elements[i] != NULL) {
			cout << i + 1 << ": ";
			for (int j = 0; j < elements[i]; j++) {
				cout << "[" << elements[i] << "]";
			}
			cout << endl;
		}
	}
	cout << endl;
}
bool rod::checkEmpty() {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[i] != NULL)
			return false;
	}

	return true;
}
