#include <iostream>

class base
{
	public :
		int a;
		virtual void print();
};

class derived : public base
{
	public :
		int a;
		void der();
};

void base::print()
{
	std::cout << "something" << std::endl;
}

void derived::der()
{
	std::cout << "derived class" << std::endl;
}

class A {
public:
    void fun_a()
    {
        std::cout << " In class A\n";
    }
};
 
class B {
public:
    void fun_b()
    {
        std::cout << " In class B\n";
    }
};
 
int main()
{
	uintptr_t t;
	
	std::cout << sizeof(t) << std::endl;
	B *x = new B();

	// A *a = reinterpret_cast<A *>(x);
	(reinterpret_cast<A *>(x))->fun_a();
}

