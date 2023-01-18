#include <iostream>

class base
{
	private :
		int k;
	protected :
		int l;

	public :
		base();
		~base();
		std::string name;
		void print_something();
};

base::base()
{
	std::cout << "base constructor" << std::endl;
}

base::~base()
{
	std::cout << "base Destructor" << std::endl;
}

class derived1 : public base
{
	public :
		derived1();
		~derived1();
		int a;
		void func();
};

derived1::~derived1()
{
	std::cout << "derived destructor" << std::endl;
}

derived1::derived1()
{
	std::cout << "derived constructor" << std::endl;
}

void base::print_something()
{
	std::cout << "something" << std::endl;
	this->l = 5;
}

void derived1::func()
{
	this->name = "hello";
	this->l = 1;
	std::cout << "func" << std::endl;
	this->print_something();
	// this->print_something();
}

int main()
{
	// base base;
	derived1 der1;

	
	// der1.print_something();
}
	