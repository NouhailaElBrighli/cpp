#include <iostream>

struct Data
{
	int	a;
	int b;
	char c;
	bool d;
};

uintptr_t serialize(Data* ptr)
{
	uintptr_t d = reinterpret_cast<uintptr_t >(ptr);
	return (d);
}

Data* deserialize(uintptr_t raw)
{
	Data *d = reinterpret_cast<Data *>(raw);
	return (d);
}

int main()
{
	Data *d = new Data;

	d->a = 1;
	d->b = 10;
	d->c = 'f';
	d->d = true;
	uintptr_t ser = serialize(d);
	std::cout << ser << std::endl;
	std::cout << d << std::endl;
	Data *ret = deserialize(serialize(d));

	std::cout << ret->d << std::endl;
	std::cout << ret->a << std::endl;
	std::cout << ret->b << std::endl;
	std::cout << ret->c << std::endl;
}