#include <iostream>
#include "concurrent_vector.h"
#include <queue>
#include <thread>


int c = 0;
bool done = false;
std::queue<int> goods;
static std::mutex mu;
std::condition_variable cond;
std::condition_variable cond2;

concurrent_vector<int> vec;

int amount = 10;

void DoWork() {
	
	for (size_t i = 0; i < amount; i++)
	{
		vec.push_back(10);
	}
}
void DoOtherWork() {
	for (size_t i = 0; i < amount; i++)
	{
		vec.push_back(5);
	}
}

void producer() {
	
	for (int i = 0; i < 500; ++i) {

	    std::unique_lock<std::mutex> lock(mu);

		goods.push(i);
		c++;
		
		cond.notify_one();
		cond2.wait(lock);
	}

	done = true;
	cond.notify_one();

}

void consumer() {
	while (!done) {

		std::unique_lock<std::mutex> lock(mu);
		
		while (!goods.empty()) {
			goods.pop();
			c--;
		}

		cond2.notify_one();
		cond.wait(lock);
		
	}
}





int main() {
	

	std::thread worker(DoWork);
	std::thread worker2(DoOtherWork);

	worker.join();
	worker2.join();
		
	vec.print();



	while(true) {

		c = 0;
		done = false;
		 
		std::thread producerThread(producer);
		std::thread consumerThread(consumer);	
		producerThread.join();
		consumerThread.join();

	
		std::cout << "Net: " << c << std::endl;


	}


	std::cin.get();
	return 0;
}