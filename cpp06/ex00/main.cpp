#include <iostream>
#include <string.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int *to_Int = (int *)av[1];
		std::cout << "int : "<< *to_Int << std::endl;
		float flt = (float)(*to_Int);
		std::cout << "Float : " << flt << std::endl;
		double dbl = static_cast<double >(flt);
		std::cout << "double : " << flt << std::endl;
	}
}