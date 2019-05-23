#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

#define MAX_ELEMENTS 6

template <class Type>
class Stack {
public:
	Stack();
	virtual ~Stack();

	void addElement(const Type& elem);
	void deleteElement();
	int getTopElement();
	void printList();
private:
	int maxElem;

};

template<class Type>
Stack<Type>::Stack() {
	number = 0;
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		elements[i] = NULL;
	}
}

template<class Type>
Stack<Type>::~Stack() {}

template<class Type>
void Stack<Type>::addElement(const Type& elem) {

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

template<class Type>
void Stack<Type>::deleteElement() {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (elements[i] == NULL) {
			elements[i - 1] = NULL;
			break;
		}
	}
	number--;
}

template<class Type>
int Stack<Type>::getTopElement() {
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

template<class Type>
void Stack<Type>::printList() {
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

#endif // !STACK_H