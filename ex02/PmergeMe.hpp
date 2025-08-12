#include <vector>

class PmergeMe
{
	private:
		std::vector<int> main;
		std::vector<int> pend;

	public:
		PmergeMe();
		~PmergeMe();
		//	####################
		//	Methodes
		std::vector<int>	sortByPairs(std::vector<int> &arguments);
		void				displaySortedList() const;
		void				setMain(std::vector<int> toSet);
};
