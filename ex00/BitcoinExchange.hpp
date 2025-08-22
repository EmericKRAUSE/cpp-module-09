#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		std::string getDate(std::string &str);
		std::string getValue(std::string &str);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		//	####################
		//	Methodes
		void loadData();
		void getResult(const std::string fileName);
};
