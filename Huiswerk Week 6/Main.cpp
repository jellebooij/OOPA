#include <iostream>
#include "Parent.h"
#include <memory>

using namespace std;

int main() {

	{
		std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
		cout << "P1:" << *p1 << endl;

		std::shared_ptr<Parent> p2 = std::make_shared<Parent>("Parent2");// roept de copy constructor aan
		cout << "P2:" << *p2 << endl;

		std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
		cout << "P3:" << *p3 << endl;

		*p3 = *p1; // roept de assignment operator aan
		cout << "P3:" << *p3 << endl;

		std::cout << "COPY COUNT: " << p1.use_count() << std::endl;

		{
			std::shared_ptr<Parent> copy1 = p1;
			std::shared_ptr<Parent> copy2 = p1;

			std::cout << "COPY COUNT: " << p1.use_count() << std::endl;
		}


		std::cout << "COPY COUNT: " << p1.use_count() << std::endl;

	}	

	


	std::cin.get();

	return 0;
}