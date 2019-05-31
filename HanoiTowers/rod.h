#ifndef _ROD_H
#define _ROD_H
#include <iostream>

using namespace std;
#define MAX_ELEMENTS 6
class rod {
public:
	int number; //number of elements
	int elements[MAX_ELEMENTS]; //list of elements

	rod();
	~rod();
	void addElement(int elem);
	void deleteElement();
	void moveElement(rod to_rod);
	int getLastElement();
	void printList();
};
#endif // !_ROD_H

rod::rod() {
	number = 0;
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		elements[i] = NULL;
	}
}
rod::~rod() {}

void rod::addElement(int elem) {

	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[0] == NULL)
		{
			elements[i] = elem; //we add the element
			break; //We finish the loop
		}
		else if (elements[i] == NULL)
		{
			if (elements[i - 1] >= elem) {
				elements[i] = elem; //we add the element
				break; //We finish the loop
			}
			else {
				cout << "Error: Your element is smaller." << endl;
				break;
			}
		}
	}
	number++;
}
void rod::deleteElement() {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[i] == NULL) {
			elements[i - 1] = NULL;
			break;
		}
	}
	number--;
}
int rod::getLastElement() {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[i] == NULL)
		{
			if (i != 0) {
				cout << endl << "Last Element: " << elements[i - 1] << endl;
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
void rod::moveElement(rod to_rod) {
	int elem = getLastElement();
	to_rod.addElement(elem);
	this->deleteElement();
}
void rod::printList() {
	cout << "Rod: ";
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[i] != NULL) {
			cout << "[" << elements[i] << "]";
		}
		else {
			cout << endl;
			i = MAX_ELEMENTS;
		}
	}
}