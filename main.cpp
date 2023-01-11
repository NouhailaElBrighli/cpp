#include <iostream>

void func()
{
	std::cout << "some instructions" << std::endl;
}
void func2()
{
	std::cout << "more instructions" << std::endl;
}

int main()
{
	void (*dispatch[])() = {&func, &func2};

	dispatch[0]();
	dispatch[1]();
}