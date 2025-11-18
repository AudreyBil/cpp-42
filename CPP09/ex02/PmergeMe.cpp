/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:14:39 by abillote          #+#    #+#             */
/*   Updated: 2025/11/15 15:11:32 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

//Todo:
//Check that output is sorted
//Review FJ structure
//Add algo for deque
//Clean the debug output

PmergeMe::PmergeMe(std::vector<int> input) {

	struct timeval t1;
	struct timeval t2;
	printContainer(input, "Before");
	gettimeofday(&t1, NULL);
	std::vector<int> output = mergeInsertionVec(input);
	gettimeofday(&t2, NULL);
	printContainer(output, "After:");
	printTime("vector", t1, t2, input.size());
	bool is_sorted = true;
	for (size_t i = 1; i < output.size(); i++) {
		if (output[i-1] > output[i]) {
			is_sorted = false;
			std::cout << output[i - 1] << " is bigger than "
			<< output[i] << std::endl;
			std::cout << "Issue is at index " << i << std::endl;
			break;
		}
	}

	if (is_sorted) {
		std::cout << "Vector is sorted" << std::endl;
	} else {
		std::cout << "Vector is not sorted" << std::endl;
	}
	//gettimeofday(&t1, NULL);
	////mergeInsertionDeq(input);
	//gettimeofday(&t2, NULL);
	//printTime("deque", t1, t2, input.size());
};

//PmergeMe::PmergeMe(const PmergeMe& other) { };

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		*this = other;
	return *this;
}

PmergeMe::~PmergeMe() { };

std::vector<Pair> PmergeMe::makePairs(std::vector<int> input)
{
	std::vector<Pair> pairs;

	for (size_t i = 0; i < input.size() - 1; i += 2) {
		Pair p;
		if (input[i] > input[i + 1]) {
			p.highest = input[i];
			p.lowest = input[i + 1];
		} else {
			p.highest = input[i + 1];
			p.lowest = input[i];
		}
		pairs.push_back(p);
	}

	return pairs;
}

std::vector<int> PmergeMe::mergeInsertionVec(std::vector<int> input)
{

	if (input.size() <= 1) {
		return input;
	}
	int stagger = -1;
	if (input.size() % 2 != 0) {
		stagger = input.back();
		input.pop_back();
	}
	std::vector<Pair> pairs = makePairs(input);
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].highest);
		pendChain.push_back(pairs[i].lowest);
	}
	std::cerr << "Main chain before sort: ";
	printContainer(mainChain, "");
	std::cerr << "Pend chain before sort: ";
	printContainer(pendChain, "");
	mainChain = mergeInsertionVec(mainChain);

	if (stagger >= 0) {
		pendChain.push_back(stagger);
	}
	std::cerr << "Pend Chain to insert (with stagger): ";
	printContainer(pendChain, "");
	insertPendChainVec(pairs, mainChain, pendChain);

	return mainChain;
}
//Add clean debug output
void PmergeMe::insertPendChainVec(std::vector<Pair> pairs, std::vector<int>& mainChain, std::vector<int>pendChain)
{
	if (!pendChain.empty()) {
		int highPairing = findPairing(pairs, pendChain[0]);
		insertMember(mainChain, pendChain[0], highPairing);
		std::cerr << "Inserted first element:" << pendChain[0] << std::endl;
		printContainer(mainChain, "Main Chain after first insertion");
	}
	if (pendChain.size() == 1) {
		return;
	}
	std::vector<int> sequence = generateJacobsthalSequence(pendChain.size() - 1);
	std::cerr << "Jacobsthal sequence: ";
	printContainer(sequence, "");

	size_t prevIndex = 0;
	for (size_t i = 0; i < sequence.size(); i++) {
		size_t maxj = std::min((size_t)sequence[i], pendChain.size() - 1);
		for (size_t j = maxj; j > prevIndex; j--) {
			std::cerr << "-----------------" << std::endl;
			std::cerr << "Pend Chain index: " << j << std::endl;
			std::cerr << "Previous index: " << prevIndex << std::endl;
			std::cerr << "Inserting " << pendChain[j] << std::endl;
			int highPairing = findPairing(pairs, pendChain[j]);
			std::cerr << "Pairing Found:" << highPairing << std::endl;
			insertMember(mainChain, pendChain[j], highPairing);
		}
		prevIndex = sequence[i];
		std::cerr << "Main chain after insertion: ";
		printContainer(mainChain, "");
		std::cerr << "-----------------" << std::endl;
	}
}

int PmergeMe::findPairing(std::vector<Pair> pairs, int lowest)
{
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].lowest == lowest) {
			return pairs[i].highest;
		}
	}
	return -1;
}

void PmergeMe::insertMember(std::vector<int>& mainChain, int toInsert, int highPairing)
{
	size_t pairIndex;
	if (highPairing == -1) {
		pairIndex = mainChain.size();
	} else {
		pairIndex = 0;
		for (size_t i = 0; i < mainChain.size(); i++){
			if (mainChain[i] == highPairing) {
				pairIndex = i;
				break;
			}
		}
	}
	std::cerr << "Pair Index is " << pairIndex << std::endl;
	size_t start = 0;
	size_t end = pairIndex;
	while (start < end) {
		size_t mid = start + (end - start) / 2;
		if (mainChain[mid] < toInsert) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	std::cerr << "Main chain index to insert: " << start << std::endl;
	mainChain.insert(mainChain.begin() + start, toInsert);
}

std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size)
{
	std::vector<int> sequence;
	int i = 1;
	int lastValue = -1;

	while (sequence.size() < size) {
		int jn = jacobsthal(i);
		if (jn > (int)size) {
			break;
		}
		if (jn != 0 && jn != lastValue) {
			sequence.push_back(jn);
			lastValue = jn;
		}
		i++;
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


void PmergeMe::printTime(const std::string& containerType, struct timeval& ts1,
						struct timeval& ts2, size_t inputSize)
{
	std::cout << "Time to process a range of " << inputSize << " elements with std::"
				<< containerType << ": ";
	displayTime(ts1, ts2);
}

void PmergeMe::displayTime(struct timeval& ts1, struct timeval& ts2)
{
	size_t totalusects1 = ts1.tv_sec * 1000000 + ts1.tv_usec;
	size_t totalusects2 = ts2.tv_sec * 1000000 + ts2.tv_usec;
	size_t diff = totalusects2 - totalusects1;
	std::cout << diff << " us" << std::endl;
}

