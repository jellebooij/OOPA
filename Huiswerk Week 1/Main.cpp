#include <iostream>
#include "Module.h"
#include "Student.h"
#include "Docent.h"

int main() {
	

	Docent d("Stephan Dquesnoi");
	Module* m = new Module("Tekenen",d);

	Student s("Piet");
	Student s2("Henk");
	Student s3("Henk");
	Student s4("Henk");
	m->addStudent(s);
	m->addStudent(s2);
	m->addStudent(s3);
	m->addStudent(s4);
	m->removeStudent(s);

	m->print();


	std::cin.get();
	return 0;
}