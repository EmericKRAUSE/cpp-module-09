#include "RPN.hpp"
#include <cctype>
#include <exception>
#include <iostream>

RPN::RPN()
{

}

RPN::RPN(const RPN &obj)
	: _stack(obj._stack)
{

}

RPN::~RPN()
{

}

RPN &RPN::operator=(const RPN &obj)
{
	if (this != &obj)
	{
		this->_stack = obj._stack;
	}
	return (*this);
}

bool RPN::isOperator(char c)
{
	char operators[4] = {'+', '-', '*', '/'};
	for (int i = 0; i < 4; i++)
	{
		if (operators[i] == c)
			return (true);
	}
	return (false);
}

int	RPN::applyOperation(int a, int b, char c)
{
	int result = 0;
	switch (c)
	{
		case '+':
			result = b + a;
			break;
		case '-':
			result = b - a;
			break;
		case '*':
			result = b * a;
			break;
		case '/':
			if (a == 0)
				throw std::runtime_error("Division by zero");
			result = b / a;
			break;
		default:
			result = 0;
	}
	return (result);
}

void	RPN::calculate(const std::string &expression)
{
	for (int i = 0; expression[i]; i++)
	{
		while (expression[i]== ' ')
			i++;
		if (isdigit(expression[i]))
		{
			this->_stack.push(expression[i] - 48);
		}
		else if (isOperator(expression[i]) && this->_stack.size() >= 2)
		{
			int a, b;
			a = this->_stack.top();
			this->_stack.pop();
			b = this->_stack.top();
			this->_stack.pop();

			std::cout	<< "Operation: "
						<< b << " "
						<< expression[i] << " "
						<< a << " "
						<< "= " << applyOperation(a, b, expression[i])
						<< std::endl;

			this->_stack.push(applyOperation(a, b, expression[i]));
		}
		else
		{
			throw std::runtime_error("Invalid character");
		}
	}
	if (this->_stack.size() == 1)
		std::cout	<< "Result: "
					<< this->_stack.top()
					<< std::endl;
	else
		throw std::runtime_error("Invalid RPN format");
}
