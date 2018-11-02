#pragma once
#include <string>
#include <vector>
#include "Student.h"
#include "Docent.h"

class Module {

private:
	std::string naam;
	int ec;

	Docent docent;
	std::vector<Student> studenten;

public:

	Module(std::string naam, Docent docent);
	
	void print();
	void addStudent(const Student& student);
	void removeStudent(Student student);
	void updateEc(int ec);

};
