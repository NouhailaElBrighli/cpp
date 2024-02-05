/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <nel-brig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:35:32 by nel-brig          #+#    #+#             */
/*   Updated: 2023/04/16 15:34:41 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Data::Data() : mp()
{
	
}

Data::~Data()
{
	
}

Data &Data::operator=(const Data &obj)
{
	if (this != &obj)
	{
		mp = obj.mp;
	}
	return(*this);
}

Data::Data(const Data &obj) : mp(obj.mp)
{
	
}

 /*******************************************************************************************/

void	Data::set_map(std::string file)
{
	std::string str;
	std::string date;
	std::string value;
	float rate;
	std::ifstream DataFile(file);
	
	getline(DataFile, str);
	while (1)
	{
		if (!getline(DataFile, date, ','))
			break;
		if (!getline(DataFile, value, '\n'))
			break;
		else
			rate = std::atof(value.c_str());
		this->mp.insert(std::make_pair(date, rate));
	}
}

std::map<std::string, float>	& Data::get_map()
{
	return(this->mp);
}

/***********************************************************************************************/

int	check_year(std::string year)
{
	std::stringstream	ss(year);
	int y;
	ss >> y;

	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error : invalid date");
	if (y < 2009 || y > 2023)
		throw std::runtime_error("Error : invalid date");
	return (y);
}

int check_month(std::string month)
{
	std::stringstream ss(month);
	int m;

	ss >> m;
	// std::cout << "|" << month << "|";
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error : invalid date");
	if (m < 1 || m > 12)
		throw std::runtime_error("Error : invalid date");
	return (m);
}

int	check_day(std::string day)
{
	std::stringstream	ss(day);
	int d;
	
	ss >> d;
	// std::cout << "|" << day << "|" << std::endl;
	// if (ss.fail() || !ss.eof())
	// 	throw std::runtime_error("Error : invalid date");
	if (d < 1 || d > 31)
		throw std::runtime_error("Error : invalid date");
	return (d);
}

int	check_date(std::string *y_m_d)
{
	int year;
	int month;
	int day;
	int leap_year = 0;

	year = check_year(y_m_d[0]);
	if (year % 4 == 0)
		leap_year = 1;
	month = check_month(y_m_d[1]);
	day = check_day(y_m_d[2]);
	if ((month == 2 && day >= 29 && leap_year == 0 ) || (month == 2 && day == 30))
		throw std::runtime_error("Error : invalid date");
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day >= 31)
		throw std::runtime_error("Error : invalid date");
	return (0);
}

int split_string(std::string *y_m_d, std::string date)
{
	std::stringstream stream(date);
	std::string str;
	int	i = 0;

	while (getline(stream, str, '-'))
	{
		if (i == 3)
			throw std::runtime_error("Error : invalid date");
		y_m_d[i++] = str;
	}
	return (0);
}

float	check_value(std::string val)
{
	float value;
	std::replace(val.begin(), val.end(), ',', '.');
	std::stringstream ss(val);
	ss >> value;
	if (ss.fail() || !ss.eof())
			throw std::runtime_error("Error :Invalid Number");
	if (value < 0 || value > 1000)
	{
		if (value < 0)
			throw std::runtime_error("Error: not a positive number");
		else
			throw std::runtime_error("Error :Invalid Number");
	}
	return (value);
}

void	CheckBadInput(std::string str)
{
	int count = std::count(str.begin(), str.end(), '|');
	if (count != 1)
	{
		str =  "Bad Input => " + str;
		throw std::runtime_error (str);
	}
}
