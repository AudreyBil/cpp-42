/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:07:36 by abillote          #+#    #+#             */
/*   Updated: 2025/08/16 15:23:21 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

};

RPN::RPN(const std::string& input)
{
	RPN::processInput(input);
}

RPN::RPN(const RPN& other)
: m_stack(other.m_stack)
{

}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		m_stack = other.m_stack;
	return *this;
}

RPN::~RPN()
{

}

void RPN::processInput(const std::string& input)
{
	std::stringstream ss(input);
	std::string token;
	while (ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			m_stack.push(token[0] - '0');
		else if (token == "+")
			calculate(&RPN::add);
		else if (token == "-")
			calculate(&RPN::subtract);
		else if (token == "*")
			calculate(&RPN::multiply);
		else if (token == "/")
			calculate(&RPN::divide);
		else
			throw std::runtime_error("Error");
	}
	if (m_stack.size() != 1){
		throw std::runtime_error("Error");
	}
	m_result = m_stack.top();

}


void RPN::calculate(int (RPN::*f)(int, int) const)
{
	if (m_stack.size() < 2)
		throw std::runtime_error ("Error");
	int b = m_stack.top();
	m_stack.pop();
	int a = m_stack.top();
	m_stack.pop();
	int result = (this->*f)(a, b);
	m_stack.push(result);
}


int RPN::add(int a, int b) const
{
	return a + b;
}

int RPN::subtract(int a, int b) const
{
	return a - b;
}

int RPN::multiply(int a, int b) const
{
	return a * b;
}

int RPN::divide(int a, int b) const
{
	if (b == 0)
		throw std::runtime_error("Error: division by zero not possible");
	return a / b;
}

int RPN::getResult() const
{
	return m_result;
}
