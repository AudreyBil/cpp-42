/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:14:39 by abillote          #+#    #+#             */
/*   Updated: 2025/08/29 15:26:29 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { };

//PmergeMe::PmergeMe(const PmergeMe& other) { };

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		*this = other;
	return *this;
}

PmergeMe::~PmergeMe() { };

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> input)
{
	(void)input;
	std::vector<int> sequence;
	sequence = generateJacobsthalSequence<std::vector<int>>(30);
	for (int i = 0; i < 30; i++)
	{
		if (sequence[i])
			std::cout << sequence[i] << std::endl;
	}
	return sequence;
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}




