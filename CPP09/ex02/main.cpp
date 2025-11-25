/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:52:42 by abillote          #+#    #+#             */
/*   Updated: 2025/11/23 14:55:56 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe_Claude.hpp"
#include <climits>

bool validateArg(const char* arg)
{
	std::string str(arg);
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	long num = std::atol(arg);
	if (num < 0 || num > INT_MAX)
		return false;
	return true;
}

bool isDuplicate(int num, const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i] == num)
			return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Not enough arguments." << std::endl;
		return 1;
	}

	std::vector<int> input;
	for (int i = 1; i < argc; i++) {
		if (validateArg(argv[i])) {
			if (!isDuplicate(atoi(argv[i]), input))
			input.push_back(atoi(argv[i]));
		} else {
			std::cerr << "Error: invalid argument: " << argv[i] << std::endl;
		}
	}

	PmergeMe FJalgo(input);

}
