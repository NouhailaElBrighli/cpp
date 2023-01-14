#include <iostream>

class Test
{
	int a;
	int *b;
	std::string name;

	public :
		Test();
		Test(const Test & old_object);
		~Test();
		void set_values(int a, int b, int c, std::string name);
		void print();
		int get_a();
		Test& operator= (const Test& old);
		// std::ostream& operator<< (std::ostream &COUT) const ;

};

int Test::get_a()
{
	return (a);
}

std::ostream& operator<<(std::ostream& COUT, Test &test1)
{
	COUT << test1.get_a();
	return(COUT);
}

Test& Test::operator=(const Test& old)
{
	if (this != &old)// where is the different ??? *this != old
	{
		delete[] this->b; // because sometimes you will have two objects with differents parametres in constructors
		this->a = old.a;
		this->name = old.name;
		this->b = new int[2];
		for (int i = 0; i < 2; i++)
			this->b[i] = old.b[i];
	}
	return(*this);
}

void 	Test::set_values(int a, int b, int c, std::string name)
{
	this->a = a;
	this->b[0] = b;
	this->b[1] = c;
	this->name = name;
}

void Test::print()
{
	std::cout << "a " << a << std::endl;
	std::cout  << "b " << b[0] << std::endl;
	std::cout << "c " << b[1] << std::endl;
	std::cout << "name " << name << std::endl;
}

Test::Test(const Test &old_object)
{
	std::cout << "call the copy constructor" << std::endl;
	this->a = old_object.a;
	this->name = old_object.name;
	this->b = new int[2];
	for (int i = 0; i < 2; i++)
		this->b[i] = old_object.b[i];
}

Test::Test()
{
	std::cout << "CONSTRUCTOR" << std::endl;
	this->b = new int[2];
}

Test::~Test()
{
	std::cout << "DESTRUCTOR" << std::endl;
	delete[] b;
}

void execute(Test test)
{
	test.set_values(10, 10, 10, "NOUHA");
	test.print();
}


//(Test test2 = test1) == (test test2(test1)); ==>both call the copy constructor 
// Test test2;
// test2 = test1; ==> this call copy assignement operator

int main()
{
	Test test1;

	test1.set_values(10, 10, 10, "nouhala");
 
	std::cout << "a" << test1 << std::endl;
}