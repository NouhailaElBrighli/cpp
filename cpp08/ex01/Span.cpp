#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->N = N;
}


Span::Span()
{

}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span :: operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->N = obj.N;
		std::copy(obj.vect.begin(), obj.vect.end(), vect.begin());
	}
	return (*this);
}

Span::~Span()
{
	
}


void Span::addNumber(int a)
{
	vect.push_back(a);
}

int Span::shortestSpan() const
{
	std::vector<int> vec;

	std::copy(vect.begin(), vect.end(), vec.begin());
	// std::vector<int>::iterator it;
	// for (it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << std::endl;
	return (0);
}

// int Span:: longestSpan()
// {

// }