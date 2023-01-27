#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->N = N;
}


Span::Span()
{
	this->N = 0;
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
		vect = obj.vect;
	}
	return (*this);
}

Span::~Span()
{

}


void Span::addNumber(int a)
{
	if (vect.size() == N)
	{
		Full full;
		throw full;
	}
	vect.push_back(a);
}

int Span::shortestSpan() const
{
	if (vect.size() < 2)
	{
		Empty empty;
		throw empty;
	}
	std::vector<int> cp = vect;
	std::sort(cp.begin(), cp.end());
	std::vector<int>::iterator it;
	int min = cp[1] - cp[0];
	int dist;
	for (unsigned int i = 0; i < cp.size() - 1 ; ++i)
	{
		dist = cp[i + 1] - cp[i];
		min = std::min(min, dist);
	}
	return(min);
}

int Span::longestSpan() const
{
	if (vect.size() < 2)
	{
		Empty empty;
		throw empty;
	}
	std::vector<int> cp = vect;
	std::sort(cp.begin(), cp.end());
	std::vector<int>::iterator it = cp.begin();
	int first = *it;
	it = cp.end();
	it--;
	int last = *it;
	int max = last - first;
	return(max);
}

// void Span::fillSpan()
// {
// 	unsigned int i = 0;
// 	while(i < N)
// 	{
// 		srand(time(NULL));
// 		this->addNumber(rand());
// 		i++;
// 	}
// }

