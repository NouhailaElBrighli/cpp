#include <iostream>

class Test
{

	public :
	static int a;
		int sum(int a, int b);
};

int Test::sum(int a, int b)
{
	return(a+b);
}

int sum1(int a, int b)
{
	return(a + b);
}

int sub(int a, int b)
{
	std::cout << "chamson sata3at" << std::endl; 
	return(10);
}

int main()
{

	// std::cout << sum1 << std::endl; 

	int (Test::*pfunc)(int, int) = &Test::sum;

	Test test;
	


	// std::cout << psum1(10, 10) << std::endl;

}