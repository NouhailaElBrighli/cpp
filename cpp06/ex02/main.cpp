#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>


Base *generate(void)
{
	Base	*b;
	int		num;

	srand (time(NULL));
	num = rand() % 3;
	switch(num)
	{
		case 0:
		{
			b = new A();
			break;
		}
		case 1:
		{
			b = new B();
			break;
		}
		default :
		{
			b = new C();
		}
	}
	return (b);
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a != nullptr)
	{
		std::cout << "A" << std::endl;
		return;
	}
	B *b = dynamic_cast<B*>(p);
	if (b != nullptr)
	{
		std::cout << "B" << std::endl;
		return;
	}
	else
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "type is A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &a = dynamic_cast<B &>(p);
		std::cout << "type is C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &a = dynamic_cast<C &>(p);
		std::cout << "type is C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main()
{
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
}