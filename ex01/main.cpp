#include "../colors.hpp"
#include "RPN.hpp"

#include <iostream>

void	ft_error(const std::string &msg)
{
	std::cerr	<< RED << "Error: " << RESET
				<< msg << std::endl;
}

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
		return (ft_error("arguments needs to be 2"), 1);
	try
	{
		rpn.calculate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< RED << "Error: " << RESET
					<< e.what() << '\n';
	}
	
}