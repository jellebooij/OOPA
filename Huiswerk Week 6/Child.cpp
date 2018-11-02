#include "Child.h"

Child::Child(string name) {
	this->name = name;
}

Child::Child(const Child& other) {
	this->name = other.name;
}

Child::~Child()
{
	std::cout << "Child " << name << " got deleted." << std::endl;
}

ostream& operator<<(ostream& os, const Child& child) {
	os << "name: " << child.name;
	return os;
}
