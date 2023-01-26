#include "iter.hpp"

template <typename T>
void iter(T *arr, unsigned int len, void (*func)(T const &))
{
	for (unsigned int i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void print (T  const &x)
{
	std::cout << "print : " << x << std::endl;
}

int main()
{
	// int tab[] = {0, 1, 5, 10};
	// char arr[] = {'a', 'b', 'c'};
	// void (*p)(int const &);
	// p = print();
	std::string arr[] = {"nouha", "khaoula", "khadija"};
	iter(arr, 3, print);
}