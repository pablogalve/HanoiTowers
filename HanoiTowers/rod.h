
class rod::public Stack {
public:
	rod();
	~rod();

	bool moveElement(Stack*);
};
rod::rod{

}
rod::~rod() {

}
bool rod::moveElement(rod to_rod) {
	int elem = getLastElement();
	to_rod.addElement(elem);
	this->deleteElement();
}