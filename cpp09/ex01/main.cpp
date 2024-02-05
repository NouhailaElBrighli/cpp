#include "RPN.hpp"

int	is_operand(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
	return(0);
}

int	is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

int is_valid(char c)
{
	if (!is_operator(c) && !is_operand(c) && c != ' ')
		return(0);
	return (1);
}

void	CheckPopPush(char c, std::stack<float> &MyStack)
{
	float a;
	float b;

	if (MyStack.size() < 2)
		throw std::runtime_error("Error : invalid expression");
	b = MyStack.top();
	MyStack.pop();
	a = MyStack.top();
	MyStack.pop();
	if (c == '+')
		MyStack.push(a + b);
	else if (c == '-')
		MyStack.push(a - b);
	else if (c == '*')
		MyStack.push(a * b);
	else if (c == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error : invalid expression");
		MyStack.push(a / b);
	}
}


void ParseInput(std::string &str)
{
	std::stack<float> MyStack;
	size_t	i = 0;
	int	num;

	if (str.size() == 0)
		throw std::runtime_error("Error : Invalid argument");
	while (i < str.size())
	{
		if (!is_valid(str[i]))
			throw std::runtime_error("Error : invalid character");
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		if (is_operand(str[i]))
		{
			num = str[i] - '0';
			MyStack.push(num);
		}
		else if (is_operator(str[i]))
			CheckPopPush(str[i], MyStack);
		i++;
	}
	if (MyStack.size() != 1)
		throw std::runtime_error("Error : invalid expression");

	std::cout << "result is: "  << MyStack.top() << std::endl;
	// std::cout << "the stack's values" << std::endl;
	// while (!MyStack.empty()) {
    //     std::cout << MyStack.top() << std::endl;
    //     MyStack.pop();
    // }
}


int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("Error : invalid argument");
		std::string str(av[1]);
		ParseInput(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
