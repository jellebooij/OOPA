#include "Student.h"

Student::Student(std::string naam) : naam(naam)
{
}

void Student::addEc(int ec)
{
	this->ec += ec;
}

int Student::getEc()
{
	return ec;
}

std::string Student::getName()
{
	return naam;
}
