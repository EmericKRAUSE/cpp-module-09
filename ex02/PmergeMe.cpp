#include <PmergeMe.hpp>

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::sortByPairs(std::vector<int> &arguments)
{
	std::vector<int>::iterator it = arguments.begin();
	int biggest;
	int smallest;

	while (it != arguments.end())
	{
		if (*it < *it + 1)
		{
			smallest = *it;
			biggest = *(it + 1);
		}
		else
		{
			smallest = *(it + 1);
			biggest = *it;
		}
		this->main.push_back(biggest);
		this->pend.push_back(smallest);
		it += 2;
	}
}
