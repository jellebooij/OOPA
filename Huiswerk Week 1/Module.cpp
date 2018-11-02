#include "Module.h"
#include <iostream>
#include <sstream>

Module::Module(std::string naam, Docent docent) : naam(naam), docent(docent){}

void Module::print()
{
	std::stringstream stream;

	stream << "Module naam: " + naam << std::endl;
	stream << "Docent: " + docent.getName() << std::endl;
	stream << "Studenten: " << std::endl;

	for (int i = 0; i < studenten.size(); i++) {
		stream << " " + studenten[i].getName() << std::endl;
	}

	std::cout << stream.str();
}

void Module::addStudent(const Student& student)
{
	studenten.push_back(student);
	auto it = studenten.end();
	it->addEc(ec);
}

void Module::removeStudent(Student student)
{
	auto it = std::find(studenten.begin(), studenten.end(), student);
	if(it != studenten.end())
		studenten.erase(it);
}

void Module::updateEc(int ec)
{
	for (int i = 0; i < studenten.size(); i++) {
		studenten[i].addEc(-(this->ec));
		studenten[i].addEc(ec);
	}

	this->ec = ec;
}
