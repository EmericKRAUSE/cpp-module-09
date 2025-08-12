#include "../colors.hpp"
#include "PmergeMe.hpp"

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <vector>

void ft_error(const std::string &msg)
{
	std::cerr	<< RED << "Error: " << RESET
				<< msg << std::endl;
}

bool isAllInt(char **argv)
{
	long int tmp;
	for (int i = 1; argv[i]; i++)
	{
		if (argv[i][0] == '\0')
			return (false);
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				return (false);
		}
		tmp = atol(argv[i]);
		if (tmp > INT_MAX)
			return (false);
	}
	return (true);
}

std::vector<int>	fillContainer(char **argv)
{
	std::vector<int> result;
	for (int i = 1; argv[i]; i++)
	{
		result.push_back(atoi(argv[i]));
	}
	return (result);
}

int main(int argc, char **argv)
{
	std::vector<int> arguments;
	PmergeMe merge;

	if (argc < 2)
		return (ft_error("No arguments"), 1);
	if (!isAllInt(argv))
		return (ft_error("All arguments must be integers"), 1);
	arguments = fillContainer(argv);
	merge.setMain(merge.sortByPairs(arguments));
	merge.displaySortedList();
}
