#include "BitcoinExchange.hpp"

void	HandleFileErrors(int ac,char *av)
{
	std::ifstream InputFile(av);
	std::ifstream DataFile("data.csv");
	std::string str;

	if (ac != 2 || !InputFile.is_open() || !DataFile.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	// std::getline(InputFile, str);
	// if (str != "date | value")
	// 	std::cout << "Error: invalid header" << std::endl;
}

void	print(std::string *y_m_d, float value)
{
	std::cout << "year :" << y_m_d[0] << "| month :" <<  y_m_d[1]  << "| day :" << y_m_d[2] <<  " value :" << value << std::endl;
}

void	ParseInputFile(char *filename, Data &data)
{
	std::string str;
	std::string date;
	float value;
	std::string val;
	std::ifstream InputFile(filename);
	std::string y_m_d[3];
	std::map<std::string, float>::iterator itr;
	std::map<std::string, float> MapData;

	MapData = data.get_map();
	getline(InputFile, str);
	if (str != "date | value")
		std::cout << "Error : invalid header" << std::endl;
	while (!InputFile.eof())
	{
		try{
			getline(InputFile, str);
			if (str.empty())
				break;
			CheckBadInput(str);
			std::stringstream line(str);
			if (!getline(line, date, '|'))
				break;
			if (!getline(line, val, '\n'))
				break;
			split_string(y_m_d, date);
			check_date(y_m_d);
			value = check_value(val);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
		itr = MapData.lower_bound(date);
		itr--;
		std::cout << date  << " =>" << val << " = " <<  itr->second * value << std::endl;
	}
}

int main(int ac, char **av)
{
	Data data;

	HandleFileErrors(ac, av[1]);
	data.set_map("data.csv");
	ParseInputFile(av[1], data);
}