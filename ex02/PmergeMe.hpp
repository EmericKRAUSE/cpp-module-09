#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vecMain;
		std::deque<int>		_deqMain;
		//	####################
		//	Private Methodes
		std::vector<int> generateJacobsthal(int size);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &obj);
		//	####################
		//	Methodes
		std::vector<int>	sortByPairs(std::vector<int> &arguments);
		std::deque<int>		sortByPairs(std::deque<int> &arguments);
		void				displayVecList() const;
		void				setMain(std::vector<int> toSet);
		void				setMain(std::deque<int> toSet);
};
