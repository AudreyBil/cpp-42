/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:14:06 by abillote          #+#    #+#             */
/*   Updated: 2025/08/29 15:27:05 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cctype>
#include <cstdlib>
#include <sstream>

class PmergeMe {

	public:
		//Constructor
		PmergeMe();
		//PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		//Vector implementation
		std::vector<int> fordJohnsonVector(std::vector<int> input);

		//List implementation
		//std::list<int> fordJohnsonList(std::list<int> input);

	private:
		
		template<typename Container>
		void printContainer(const Container& container, const std::string& prefix);

		template<typename Container>
		Container generateJacobsthalSequence(size_t size);

		int jacobsthal(int n);

};

template<typename Container>
void PmergeMe::printContainer(const Container& container, const std::string& prefix)
{
	typename Container::iterator it;
	std::cout << prefix << std::endl;
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename Container>
Container PmergeMe::generateJacobsthalSequence(size_t size)
{
	Container sequence;
	int i = 1;
	int lastValue = -1;

	while (sequence.size() < size) {
		int jn = jacobsthal(i);
		if (jn != 0 && jn != lastValue) {
			sequence.push_back(jn);
			lastValue = jn;
		}
		i++;
	}
	return sequence;
}



#endif
