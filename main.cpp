#include <iostream>

class base
{
	private :
		int k;
	protected :
		int l;

	public :
		base();
		virtual ~base();
		virtual void print_something() = 0;
		void hello();
		std::string name;
};

base::base()
{
	std::cout << "base constructor" << std::endl;
}

void base::hello()
{
	std::cout << "hello" << std::endl;
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
	this->hello();
}

void print(base *der)
{
	der->print_something();
}

int main()
{
	// base b;
	base *der1 = new derived1();

	derived1 a;
	derived1 b;

	delete der1;
	// print(der1);
	// delete der1;
}
