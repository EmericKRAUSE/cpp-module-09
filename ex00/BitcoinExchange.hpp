#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
	public:
		BitcoinExchange();
		~BitcoinExchange();

		//	####################
		//	Methodes
		void loadData();
		void getResult(const std::string fileName);
};
