#include "BitcoinExchange.hpp"

#include <fstream>
#include <exception>
#include <iostream>
#include <stdlib.h>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

//	####################
//	Methodes
void	BitcoinExchange::loadData()
{
	std::ifstream	dataFile("data.csv");
	std::string		header;
	std::string		key;
	std::string		value;

	if (!dataFile.is_open())
		throw std::runtime_error("Error while opening data file");

	std::getline(dataFile, header);
	while (std::getline(dataFile, key, ',') && std::getline(dataFile, value))
		this->_data[key] = atof(value.c_str());
}

std::string getValue(std::string &str)
{
	size_t	start = str.find('|');
	size_t	end = str.length() - 1;
	if (start == std::string::npos)
		return ("");
	start++;

	while (start < end && str[start] == ' ')
		start++;
	while (end > start && str[end] == ' ')
		end--;
	return (str.substr(start, end - start + 1));
}

std::string getDate(std::string &str)
{
	size_t	start = 0;
	size_t	end = str.find('|');
	if (end == std::string::npos || end == 0)
		return ("");
	end--;

	while (start < end && str[start] == ' ')
		start++;
	while (end > start && str[end] == ' ')
		end--;
	return (str.substr(start, end - start + 1));
}

void	BitcoinExchange::getResult(const std::string fileName)
{
	std::ifstream	inputFile(fileName.c_str());
	std::string		header;
	std::string		line;
	std::string		date;
	std::string		value;

	if (!inputFile.is_open())
		throw std::runtime_error("Error while opening input file");
	std::setlocale(LC_NUMERIC, "C");
	std::getline(inputFile, header);
	while (std::getline(inputFile, line))
	{
		if (line.find('|') != std::string::npos)
		{
			date = getDate(line);
			value = getValue(line);
			if (date.empty() || value.empty())
				std::cout << "Error: empty line" << std::endl;
			else if (atof(value.c_str()) < 0 || atof(value.c_str()) > 1000)
				std::cout << "Error: invalid value" << std::endl;
			else
			{
				std::map<std::string, float>::iterator it = this->_data.lower_bound(date);
				if (it == this->_data.begin() && it->first != date)
				{
					std::cout << "Error: invalid date" << std::endl;
					continue;
				}
				else if (it->first != date)
				{
					it--;
				}
				std::cout << it->first << " => "
						  << value << " = "
						  << this->_data[it->first] * atof(value.c_str()) << std::endl;
			}
		}
		else
			std::cout << "Error: bad format" << std::endl;
	}
}
