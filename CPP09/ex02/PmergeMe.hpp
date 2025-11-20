/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:14:06 by abillote          #+#    #+#             */
/*   Updated: 2025/11/20 14:07:43 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <algorithm>

#define CLR_RED     "\033[31m"
#define CLR_GREEN   "\033[32m"
#define CLR_YELLOW  "\033[33m"
#define CLR_BLUE    "\033[34m"
#define CLR_MAGENTA "\033[35m"
#define CLR_CYAN    "\033[36m"
#define CLR_RESET   "\033[0m"

struct Pair {
		int lowest;
		int highest;
	};

class PmergeMe {

	public:
		//Constructor
		PmergeMe(std::vector<int> input);
		//PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		// debug print
		static void dbgLog(const char* color, const std::string& tag,
					const std::string& msg);

	private:

		void printTime(const std::string& containerType, struct timeval& ts1,
						struct timeval& ts2, size_t inputSize);
		void displayTime(struct timeval& ts1, struct timeval& ts2);

		//Vector implementation
		std::vector<int> mergeInsertionVec(std::vector<int> input);
		std::vector<struct Pair> makePairs(std::vector<int> input);
		void insertPendChainVec(std::vector<Pair> pairs, std::vector<int>& mainChain, std::vector<int>pendChain);
		int findPairing(std::vector<Pair>& pairs, int lowest);
		void insertMember(std::vector<int>& mainChain, int toInsert, int highPairing);

		//Deque implementation
		std::deque<int> mergeInsertionDeq(std::vector<int> input);

		template<typename Container>
		void printContainer(const Container& container, const std::string& prefix = "");

		std::vector<int> generateJacobsthalSequence(size_t size);

		int jacobsthal(int n);

		//Counter
		size_t m_counter;

		// debug state
		static bool m_debugEnabled;

};

template<typename Container>
void PmergeMe::printContainer(const Container& container, const std::string& prefix)
{
	typename Container::const_iterator it;
	if (!prefix.empty())
		std::cout << prefix << std::endl;
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif
