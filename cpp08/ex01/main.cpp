#include "Span.hpp"

int main()
{
	Span sp(10);

	sp.addNumber(10);
	sp.addNumber(15);
	sp.addNumber(20);

	sp.shortestSpan();
}