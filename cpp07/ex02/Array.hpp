#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <class T>
class Array
{
	private :
		int len;
		T *arr;
	public :
		Array()
		{
			arr = new T;
			len = 0;
		}
		Array(unsigned int n)
		{
			arr = new T[n];
			len = n;
		}
		Array (Array &rhs)
		{
			this->arr = NULL;
			*this = rhs;
		}
		Array &operator=(Array &rhs)
		{
			if (this != &rhs)
			{
				if (arr != NULL)
					delete [] arr;
				this->len = rhs.len;
				arr = new T[len];
				for (int i = 0; i < len; i++)
					arr[i] = rhs.arr[i];
			}
			return (*this);
		}
		~Array()
		{
			delete [] arr;
		}
		class WrongIndex : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Index out of bound");
			}
		};
		T & operator[](int N)
		{
			if(N < 0 || N >= len)
			{
				WrongIndex Wrong;
				throw Wrong;
			}
			return (arr[N]);
		}
		unsigned int size() const
		{
			return (len);
		}
};


#endif