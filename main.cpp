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
		void print_something();
		std::string name;
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
		void print_something();
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
	std::cout << "base something" << std::endl;
}

void derived1::print_something()
{
	std::cout << "derived something" << std::endl;
}

void print(base *der)
{
	der->print_something();
}

int main()
{
	// base b;
	
	derived1 *der1 = new derived1();

	print(der1);
	delete der1;
}
