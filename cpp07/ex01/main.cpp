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
	std::cout << x << std::endl;
}


int main()
{
	char array[] = {'a', 'b', 'c'};
	std::string str[] = {"nouha", "khaoula", "khadija"};
	int tab[] = {0, 1, 5, 10};
	iter(array, 3, print);
	iter(str, 3, print);
	iter(tab, 4, print);
}

