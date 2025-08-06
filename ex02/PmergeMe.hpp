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
		void sortByPairs(std::vector<int> &arguments);
};
