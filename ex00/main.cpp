#include <iostream>
#include <string>

#include "../colors.hpp"
#include "BitcoinExchange.hpp"

void	ft_error(const std::string &msg)
{
	std::cerr	<< RED << "Error: " << RESET
				<< msg << std::endl; 
}

int main(int argc, char **argv)
{
	BitcoinExchange exchange;
	if (argc != 2)
		return(ft_error("need one argument"), 1);
	try
	{
		exchange.loadData();
		exchange.getResult(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}