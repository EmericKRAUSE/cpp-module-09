#include "PmergeMe.hpp"
#include "../colors.hpp"

#include <iostream>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &obj)
	: _vecMain(obj._vecMain), _deqMain(obj._deqMain)
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		_vecMain = obj._vecMain;
		_deqMain = obj._deqMain;
	}
	return (*this);
}

std::vector<int>	PmergeMe::generateJacobsthal(int size)
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

std::vector<int>	PmergeMe::sortByPairs(std::vector<int> &arguments)
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
			itInsert = std::lower_bound(main.begin(), main.end(), pend[start]);
			main.insert(itInsert, pend[start]);
			start++;
		}
	}
	for (std::vector<int>::iterator it = pend.begin() + jSeq.back() + 1; it < pend.end(); it++)
	{
		itInsert = std::lower_bound(main.begin(), main.end(), *it);
		main.insert(itInsert, *it);
	}
	return (main);
}

std::deque<int> PmergeMe::sortByPairs(std::deque<int> &arguments)
{
	std::deque<int> main, pend;
	std::deque<int>::iterator it = arguments.begin();
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
	std::deque<int>::iterator itInsert = std::lower_bound(main.begin(), main.end(), pend[0]);

	main.insert(itInsert, pend[0]);

	for (int i = jSeq.size() - 1; i > 0; i--)
	{
		int	start = jSeq[i - 1] + 1;
		int	end = jSeq[i];
		while (start <= end)
		{
			itInsert = std::lower_bound(main.begin(), main.end(), pend[start]);
			main.insert(itInsert, pend[start]);
			start++;
		}
	}
	for (std::deque<int>::iterator it = pend.begin() + jSeq.back() + 1; it < pend.end(); it++)
	{
		itInsert = std::lower_bound(main.begin(), main.end(), *it);
		main.insert(itInsert, *it);
	}
	return (main);
}

void	PmergeMe::displayVecList() const
{
	std::cout << "\n" << CYN << "After:  " << RESET;
	std::vector<int>::const_iterator it = this->_vecMain.begin();
	while (it < this->_vecMain.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	PmergeMe::setMain(std::vector<int> toSet)
{
	this->_vecMain = toSet;
}

void	PmergeMe::setMain(std::deque<int> toSet)
{
	this->_deqMain = toSet;
}