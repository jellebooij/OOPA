#pragma once
#include <vector>
#include <mutex>

template <typename T>
class concurrent_vector {

private:
	std::vector<T> vec;
	std::mutex mu;


public:

	void push_back(T value) {
		mu.lock();
		vec.push_back(value);
		mu.unlock();
	}


	//Ik heb er voor gekozen om een copy te returnen zodat er geen errors kunnen ontstaan als twee theards aan het zelfde element zitten
	T operator[](int index) {
		return vec[index];
	}

	void print() {

		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << std::endl;
		}
	}

};