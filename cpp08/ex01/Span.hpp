#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private :
		std::vector <int> vect;
		unsigned int N;
	public :
		Span();
		Span(const Span &obj);
		Span &operator=(const Span &obj);
		~Span();
		Span(unsigned int N);
		void addNumber(int a);
		int shortestSpan()const ;
		int longestSpan()const ;

};
#endif