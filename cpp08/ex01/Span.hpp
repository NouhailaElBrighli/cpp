#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

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
		int shortestSpan()const;
		int longestSpan()const ;
		class Full : public std::exception
		{
			virtual const char *what() const throw()
			{
				return("no space left");		
			}
		};
		class Empty : public std::exception
		{
			virtual const char *what() const throw()
			{
				return("not enough element");		
			}
		};
		template<typename T>
		void AddRange(T begin, T end)
		{
			if (vect.size() + std::distance(begin, end) > this->N)
			{
				Full full;
				throw full;
			}
			vect.insert(this->vect.end(), begin, end);
			// std::vector<int>::iterator it;
			// for (it = vect.begin(); it != vect.end(); it++)
			// 	std::cout << *it << std::endl;
		}
};

#endif