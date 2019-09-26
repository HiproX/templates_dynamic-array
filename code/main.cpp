#include "array.h"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "\tTest dynamic array" << std::endl;
	
	Array<int> a{ 10 };
	std::cout << "a: " << a << std::endl
		<< "a.size(): " << a.size()
		<< "\ta.capacity(): " << a.capacity() << std::endl;

	int N = 10;
	a.assign(N);
	std::cout << "\na.assign(N): " << a << std::endl
		<< "a.size(): " << a.size() << "\ta.capacity(): " << a.capacity() << std::endl;
	
	a.clear();
	std::cout << "\nMethod Array<T>::clear complete!" << std::endl;
	std::cout << "a.size(): " << a.size()
		<< "\ta.capacity(): " << a.capacity() << std::endl;
	
	for (Array<int>::size_type i{}; i < 15; i++)
	{
		a.push_back(i + 1);
	}
	std::cout << "\nMethods Array<T>::push_back complete!" << std::endl;
	std::cout << "a.size(): " << a.size()
		<< "\ta.capacity(): " << a.capacity() << std::endl;

	int M = 40;
	a.resize(M);
	std::cout << "\na.resize(M): " << a << std::endl
		<< "a.size(): " << a.size()
		<< "\ta.capacity(): " << a.capacity() << std::endl;

	std::cout << "\na.front(): " << a.front()
		<< "\ta.back(): " << a.back() << std::endl;

	std::cout << "\nTest Array<T>::pop_back:" << std::endl;
	while (!a.empty())
	{
		a.pop_back();
		std::cout << a << std::endl;
	}
	
	std::cout << "\na.empty(): " << std::boolalpha << a.empty() << std::endl;

	std::cin.get();
	while (std::cin.ignore(0x400, '\n'));
	std::cin.get();
}