#include <iostream>
#include <array>
#include <vector>
#include <list>

int main()
{
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(2);
	lst.push_back(10);
	std::list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
}

