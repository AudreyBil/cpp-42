/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:14:39 by abillote          #+#    #+#             */
/*   Updated: 2025/11/18 14:58:36 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

//Check if input sorted before using algo
//Add deque

//debug member definition
bool PmergeMe::m_debugEnabled = true;

void PmergeMe::dbgLog(const char* color, const std::string& tag,
					const std::string& msg)
{
	if (!m_debugEnabled) return;
	std::cerr << color << "[" << tag << "] " << msg << CLR_RESET << std::endl;
}

static std::string toStr(int v) {
	std::ostringstream oss;
	oss << v;
	return oss.str();
}


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
			dbgLog(CLR_RED, "Error", toStr(output[i - 1]) + " is bigger than " + toStr(output[i]));
			dbgLog(CLR_RED, ">>>", "Issue is at index " + toStr(i));
			break;
		}
	}

	if (is_sorted) {
		dbgLog(CLR_GREEN, "SUCCESS", "Vector is sorted");
	} else {
		dbgLog(CLR_MAGENTA, "FAIL", "Vector is not sorted");
	}

	if (input.size() == output.size()) {
		dbgLog(CLR_GREEN, "SUCCESS", "All numbers are present in the output");
	} else {
		dbgLog(CLR_MAGENTA, "FAIL", "Missing numbers in the output");
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

	dbgLog(CLR_MAGENTA, "Step", "Making Pairs");
	for (size_t i = 0; i < pairs.size(); i++) {
		dbgLog(CLR_YELLOW, "Pair " + toStr(i), toStr(pairs[i].lowest) + "-" + toStr(pairs[i].highest));
	}

	return pairs;
}

std::vector<int> PmergeMe::mergeInsertionVec(std::vector<int> input)
{
	//----Base case: end of recursion----//
	//----Only one int in Main Chain----//
	if (input.size() <= 1) {
		dbgLog(CLR_YELLOW, "Base Case", "Only one member in Main Chain");
		return input;
	}

	//----If odd numbers: remove the last one and store it in a var----///
	int stagger = -1;
	if (input.size() % 2 != 0) {
		stagger = input.back();
		input.pop_back();
	}

	//----Step 1 : Making Pairs----//
	std::vector<Pair> pairs = makePairs(input);
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].highest);
		pendChain.push_back(pairs[i].lowest);
	}

	dbgLog(CLR_MAGENTA, "Step", "Pushing highest pair members in Main Chain and lowest in Pending Chain");
	dbgLog(CLR_YELLOW, "Main Chain", "");
	printContainer(mainChain);
	dbgLog(CLR_YELLOW, "Pending Chain", "");
	printContainer(pendChain);

	//Step 2 : - Recursively sort largest numbers//
	dbgLog(CLR_CYAN, "Recursion", "Entering Main Chain recursion");
	mainChain = mergeInsertionVec(mainChain);
	dbgLog(CLR_CYAN, "Recursion", "Leaving recursion");

	//If stagger - add it back into Pending Chain//
	if (stagger >= 0) {
		dbgLog(CLR_YELLOW, "Stagger", "Adding Stagger in Pending Chain");
		pendChain.push_back(stagger);
		dbgLog(CLR_YELLOW, "Pending Chain", "");
		printContainer(pendChain);
	}
	//Step 3: Insert Pending numbers into Main Chain//
	insertPendChainVec(pairs, mainChain, pendChain);

	return mainChain;
}

void PmergeMe::insertPendChainVec(std::vector<Pair> pairs, std::vector<int>& mainChain, std::vector<int>pendChain)
{
	dbgLog(CLR_MAGENTA, "Step", "Inserting Pending Chain into Main Chain");
    dbgLog(CLR_YELLOW, "Main Chain", "");
    printContainer(mainChain);
    dbgLog(CLR_YELLOW, "Pending Chain", "");
    printContainer(pendChain);

	//Insert first member of the PendChain first
	if (!pendChain.empty()) {
		int highPairing = findPairing(pairs, pendChain[0]);
		dbgLog(CLR_CYAN, "Insert", "Inserting first pending element: " + toStr(pendChain[0]) + " (pair: " + toStr(highPairing) + ")");
		insertMember(mainChain, pendChain[0], highPairing);
	}
	if (pendChain.size() == 1) {
		return;
	}

	//Generate Jacobstahl sequence
	std::vector<int> sequence = generateJacobsthalSequence(pendChain.size() - 1);
	dbgLog(CLR_MAGENTA, "Step", "Generating Jacobstahl sequence: ");
	printContainer(sequence, "");

	//Insert Pending Chain into Main Chain
	size_t prevIndex = 0;
	for (size_t i = 0; i < sequence.size(); i++) {
		size_t maxj = std::min((size_t)sequence[i], pendChain.size() - 1);
		for (size_t j = maxj; j > prevIndex; j--) {
			int highPairing = findPairing(pairs, pendChain[j]);
			dbgLog(CLR_CYAN, "Insert", "Inserting element: " + toStr(pendChain[j]) + " (pair: " + toStr(highPairing) + ")");
			insertMember(mainChain, pendChain[j], highPairing);
		}
		prevIndex = sequence[i];
	}
}

int PmergeMe::findPairing(std::vector<Pair>& pairs, int lowest)
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
	//Fill in remaining indices after last Jacobstahl number
	if (!sequence.empty() && sequence.back() < (int)size) {
		for (int j = sequence.back() + 1; j <= (int)size; j++) {
			sequence.push_back(j);
		}
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

