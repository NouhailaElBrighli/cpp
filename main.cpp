#include <iostream>

void func()
{
	std::cout << "hiiii";
}


template <typename T>
void print(T val)
{
	std::cout << val << std::endl;
}


int main()
{
	// print(5.012344f);
}

