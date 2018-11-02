#pragma once

#include <string>
#include <iostream>

using namespace std;

class Child {
public:
	Child(string name);
	Child(const Child& other);
	~Child();

private:
	string name;

public:
	friend ostream& operator<<(ostream& os, const Child& child);
};