#include <iostream>
#include <string>
#include "Queue.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <numeric>
 

template<typename T>
void swap(T* a, T* b) {
	
	T temp = *a;
	*a = *b;
	*b = temp;

}

template<typename T>
int partition(T arr[], int low, int high)
{
	T pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

template<typename T>
void sort(T myArray[], int low, int high) {

	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(myArray, low, high);

		// Separately sort elements before 
		// partition and after partition 
		sort(myArray, low, pi - 1);
		sort(myArray, pi + 1, high);
	}


}

int main() {

	std::string poep[5] {
		"aard", "geert", "berend", "zjacky", "claudia"
	};
	
	Queue<std::string> ints;
	ints.PushBack("aard");
	ints.PushBack("geert");
	ints.PushBack("berend");
	ints.PushBack("zjacky");
	ints.PushBack("claudia");

	std::cout << ints.PopFront() << std::endl;
	std::cout << std::endl;

	ints.PrintList();

	std::cout << std::endl;

	int n = sizeof(poep) / sizeof(poep[0]);
	sort(poep,0, n - 1);

	for (size_t i = 0; i < n; i++)
	{
		std::cout << poep[i] << std::endl;
	}
	std::cout <<  std::endl << std::endl << std::endl;


	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	std::vector<std::string> colours1 = colours;
	
	std::sort(colours1.begin(),colours1.end());
	std::vector<std::string>::iterator it = std::find(colours1.begin(), colours1.end(), "purple");



	std::vector<std::string> low(colours1.begin(), it);
	std::vector<std::string> high(it, colours1.end());

	for (size_t i = 0; i < high.size(); i++)
	{
		std::cout << high[i] << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;

	// 2) alle elementen UPPERCASE te maken.
	std::vector<std::string> colours2 = colours;
	for (size_t i = 0; i < colours2.size(); i++)
	{
		std::transform(colours2[i].begin(), colours2[i].end(), colours2[i].begin(), [](char c) { return std::toupper(c); });
	}

	for (size_t i = 0; i < colours2.size(); i++)
	{
		std::cout << colours2[i] << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;

	// 3) alle dubbele te verwijderen
	std::vector<std::string> colours3 = colours;
	std::sort(colours3.begin(), colours3.end());
	colours3.erase(std::unique(colours3.begin(), colours3.end()), colours3.end());

	for (size_t i = 0; i < colours3.size(); i++)
	{
		std::cout << colours3[i] << std::endl;
	}

	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// 1) alle negatieve elementen te verwijderen
	std::cout << std::endl << std::endl << std::endl;
	std::vector<double> numbers1 = numbers;
	numbers1.erase(std::remove_if(numbers1.begin(), numbers1.end(), [](float f) {return(f < 0); }));

	for (size_t i = 0; i < numbers1.size(); i++)
	{
		std::cout << numbers1[i] << std::endl;
	}

	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	std::cout << std::endl << std::endl << std::endl;
	std::vector<double> numbers2 = numbers;

	for (size_t i = 0; i < numbers2.size(); i++)
	{
		std::cout << (bool)((int)numbers2[i] % 2 == 0) << std::endl;
	}

	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	std::cout << std::endl << std::endl << std::endl;
	std::vector<double> numbers3 = numbers;

	std::cout << std::accumulate(begin(numbers3), end(numbers3), 0.0f) << std::endl;
	//numbers3 = numbers;
	std::cout << (std::accumulate(begin(numbers3), end(numbers3), 0.0f))/numbers3.size() << std::endl;
	//numbers3 = numbers;
	std::cout << std::accumulate(begin(numbers3), end(numbers3), 1.0f,std::multiplies<double>()) << std::endl;


	std::cin.get();

	return 0;
}