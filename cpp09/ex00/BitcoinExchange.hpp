#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

class Data
{
	private :
		std::map <std::string, float> mp;
	public :
		Data();
		Data(const Data &obj);
		Data &operator=(const Data &obj);
		~Data();
		void	set_map(std::string file);
		std::map<std::string, float>	&get_map();
};

float	check_value(std::string val);
int		check_day(std::string day);
int		check_month(std::string month);
int		check_year(std::string year);
int		check_date(std::string *y_m_d);
int		split_string(std::string *y_m_d, std::string date);
void	CheckBadInput(std::string str);
