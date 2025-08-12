#include "PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

std::vector<int> generateJacobsthal(int size)
{
	std::vector<int>			jacobsthalSequence;
	int							result;

	if (size <= 0)
		return (jacobsthalSequence);
	jacobsthalSequence.push_back(0);
	if (size == 1)
		return (jacobsthalSequence);
	jacobsthalSequence.push_back(1);

	for (int i = 2; ; i++)
	{
		result = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];
		if (result >= size)
			break;
		jacobsthalSequence.push_back(result);
	}
	return (jacobsthalSequence);
}

std::vector<int> PmergeMe::sortByPairs(std::vector<int> &arguments)
{
	std::vector<int> main, pend;
	std::vector<int>::iterator it = arguments.begin();
	int a;
	int b;

	if (arguments.size() <= 1)
		return (arguments);

	while (it != arguments.end() && it + 1 != arguments.end())
	{
		a = *it;
		b = *(it + 1);

		if (b > a)
			std::swap(a, b);
		main.push_back(a);
		pend.push_back(b);
		it += 2;
	}
	if (it != arguments.end())
		main.push_back(*it);

	main = sortByPairs(main);

	std::vector<int>			jSeq = generateJacobsthal(pend.size());
	std::vector<int>::iterator	itInsert = std::lower_bound(main.begin(), main.end(), pend[0]);

	main.insert(itInsert, pend[0]);

	for (int i = jSeq.size() - 1; i > 0; i--)
	{
		int	start = jSeq[i - 1] + 1;
		int	end = jSeq[i];
		while (start <= end)
		{
			//std::cout << "start: " << start << "end: " << end << std::endl;
			itInsert = std::lower_bound(main.begin(), main.end(), pend[start]);
			//std::cout << "insert[" << i << "]: " << pend[start] << std::endl;
			main.insert(itInsert, pend[start]);
			start++;
			//std::cout << "\n";
		}
	}
	return (main);
}

void	PmergeMe::displaySortedList() const
{
	std::vector<int>::const_iterator it = this->main.begin();
	while (it < this->main.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void	PmergeMe::setMain(std::vector<int> toSet)
{
	this->main = toSet;
}

