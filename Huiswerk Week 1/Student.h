#pragma once
#include <string>

class Student {

private:
	std::string naam;
	int ec;

public:
	Student(std::string naam);
	void addEc(int ec);
	int getEc();
	std::string getName();

	bool operator== (const Student &arg)
	{
		return arg.naam == naam;
	}

};