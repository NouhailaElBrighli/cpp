#include <iostream>
#include <exception>

class ClassException : public std::exception
{
	int a;
	virtual const char * what() const throw();
};

const char *ClassException::what() const throw()
{
	return("negative"); 
}

class Parent{
	std::string name;
	int count;
	public :
		void set(std::string name, int count);
};

void Parent::set(std::string name, int count)
{
	if (count < 0)
	{
		ClassException test;
		throw test;
	}
	this->name = name;
	this->count = count;
	std::cout << "everythig is ok" << std::endl;
}

int main(){
	Parent p;

	try
	{
		p.set("nouha", -15);
	}
	// catch (std::exception &e)
	// {
	// 	std::cout << "catch exception " << e.what();
	// }
	catch(...)
	{
		std::cout << "EXCEPTIOIN" << std::endl;
	}
	// std::cout << "here" << std::endl;
}