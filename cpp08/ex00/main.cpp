#include "easyfind.hpp"

template <typename T>
void easyfind(T &container, int a)// why we should use reference
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), a);
	if (it != container.end())
		std::cout << "element found : " << *it << std::endl;
	else
		std::cout << "element not found" << std::endl;
}

int main()
{
	std::vector<int> vec;

	vec.push_back(15);
	vec.push_back(16);
	vec.push_back(17);
	vec.push_back(18);

	std::array<int, 5> arr = {1,4,3,4,-4};

	easyfind(arr, 0);
	//easyfind(vec, 20);

}