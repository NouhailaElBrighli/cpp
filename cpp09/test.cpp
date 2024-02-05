#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <ctime>

class test
{
	private :
		std::vector<int> vec;
	public :
		test()
		{

		}
		test(const test &obj) 
		{
			this->vec = obj.vec;
		}
		void push(int a)
		{
			vec.push_back(a);
		}
		void	print()
		{
			std::vector<int> ::iterator itr;

			for (itr = vec.begin(); itr != vec.end(); itr++)
				std::cout << *itr << std::endl;
		}
};

int main()
{
	test test1;
	test1.push(5);
	test test2(test1);
	test2.push(10);
	std::cout << "first vec" << std::endl;
	test1.print();
	std::cout << "second vec" << std::endl;
	test2.print();
}