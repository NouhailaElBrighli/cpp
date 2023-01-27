#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <deque>

template <typename T, class container=std::deque<T> >
class MutantStack :public std::stack<T>
{
	private:

	public:
		MutantStack()
		{
		}
		~MutantStack()
		{
		}
		MutantStack(const MutantStack &stack)
        {
            *this = stack;
        }
		MutantStack &operator=(const MutantStack &obj)
		{
			this->c = obj.c;
		}
		typedef typename container::iterator iterator;
		iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};


#endif