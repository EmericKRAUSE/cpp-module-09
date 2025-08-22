#include "../colors.hpp"
#include "PmergeMe.hpp"

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>

void	ft_error(const std::string &msg)
{
	std::cerr	<< RED << "Error: " << RESET
				<< msg << std::endl;
}

bool	isAllInt(char **argv)
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

void	displayArguments(std::vector<int> args)
{
	std::cout << "\n" << CYN << "Before: " << RESET;
	for (std::vector<int>::iterator it = args.begin(); it != args.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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
	std::vector<int>	vecArgs;
	std::deque<int>		deqArgs;
	PmergeMe merge;

	if (argc < 2)
		return (ft_error("No arguments"), 1);
	if (!isAllInt(argv))
		return (ft_error("All arguments must be integers"), 1);

	vecArgs = fillContainer(argv);
	displayArguments(vecArgs);
	deqArgs = std::deque<int>(vecArgs.begin(), vecArgs.end());

	clock_t start = clock();
	merge.setMain(merge.sortByPairs(vecArgs));
	clock_t end = clock();
	double timeElapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	
	merge.displayVecList();
	std::cout << CYN << "Time to process a range of "
			  << vecArgs.size()
			  << " elements with std::vector : " << RESET
			  << std::fixed << std::setprecision(5) << timeElapsed << " us"
			  << std::endl;

	start = clock();
	merge.setMain(merge.sortByPairs(deqArgs));
	end = clock();
	timeElapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << CYN << "Time to process a range of "
			  << deqArgs.size()
			  << " elements with std::deque : " << RESET
			  << std::fixed << std::setprecision(5) << timeElapsed << " us"
			  << std::endl;
}
