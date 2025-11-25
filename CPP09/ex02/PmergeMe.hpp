#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

#define CLR_RED "\033[31m"
#define CLR_GREEN "\033[32m"
#define CLR_YELLOW "\033[33m"
#define CLR_BLUE "\033[34m"
#define CLR_MAGENTA "\033[35m"
#define CLR_CYAN "\033[36m"
#define CLR_RESET "\033[0m"

struct Pair {
    int lowest;
    int highest;
};

class PmergeMe {
public:
    PmergeMe(std::vector<int> input);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static void dbgLog(const char* color, const std::string& tag,
                       const std::string& msg);

private:
    void printTime(const std::string& containerType, struct timeval& ts1,
                   struct timeval& ts2, size_t inputSize);
    void displayTime(struct timeval& ts1, struct timeval& ts2);

	//Vector Implementation
    std::vector<int> mergeInsertionVec(std::vector<int> input);
    std::vector<struct Pair> makePairsVec(std::vector<int> input);
    void insertPendChainVec(std::vector<int>& mainChain,
                            std::vector<int>& pendChain, size_t numPairs);
    std::vector<size_t> generateInsertionOrderVec(size_t pendSize);

	//Deque Implementation
    std::deque<int> mergeInsertionDeq(std::deque<int> input);
	std::deque<struct Pair> makePairsDeq(std::deque<int> input);
    void insertPendChainDeq(std::deque<int>& mainChain,
                            std::deque<int>& pendChain, size_t numPairs);
    std::deque<size_t> generateInsertionOrderDeq(size_t pendSize);

    template <typename Container>
    void printContainer(const Container& container,
                        const std::string& prefix = "",
                        const std::string& toPrint = "");

    size_t jacobsthal(int n);

    size_t m_counter;
    static bool m_debugEnabled;
};

template <typename Container>
void PmergeMe::printContainer(const Container& container,
                              const std::string& prefix,
                              const std::string& toPrint) {
    typename Container::const_iterator it;
    if (toPrint.empty() && !m_debugEnabled) {
        return;
    }
    if (!prefix.empty()) std::cout << prefix << " ";
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif
