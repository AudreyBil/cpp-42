/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:07:03 by abillote          #+#    #+#             */
/*   Updated: 2025/08/16 15:21:18 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <sstream>

class RPN {
	public:
		//Constructor
		RPN();
		RPN(const std::string& input);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int getResult() const;



	private:
		std::stack<int> m_stack;
		int m_result;

		void processInput(const std::string& input);
		int add(int a, int b) const;
		int subtract(int a, int b) const;
		int multiply(int a, int b) const;
		int divide(int a, int b) const;
		void calculate(int (RPN::*f)(int, int) const);
};

#endif
