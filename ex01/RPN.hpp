#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int>	_stack;
		//	####################
		//	Private Methodes
		bool isOperator(char c);
		int	applyOperation(int a, int b, char c);

	public:
		RPN();
		RPN(const RPN &obj);
		~RPN();
		RPN &operator=(const RPN &obj);

		//	####################
		//	Methodes
		void calculate(const std::string &expression);
};