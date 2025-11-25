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

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    PmergeMe(std::vector<int> input);

    static void dbgLog(const char* color, const std::string& tag,
                       const std::string& msg);

private:
    struct Pair {
        int lowest;
        int highest;
    };

    // Utility functions (non templated)
    size_t jacobsthal(int n);
    void printTime(const std::string& containerType, struct timeval& ts1,
                   struct timeval& ts2, size_t inputSize);
    void displayTime(struct timeval& ts1, struct timeval& ts2);

    // Utility functions (templated)
    template <typename Container>
    void printContainer(const Container& container,
                        const std::string& prefix = "",
                        const std::string& toPrint = "");

    template <typename Container>
    Container generateInsertionOrder(size_t pendSize);

    template <typename Container>
    void processAndValidate(const std::string& typeName, const Container& input,
                            Container& output, struct timeval& ts1,
                            struct timeval& ts2);

    // Vector Implementation
    std::vector<int> mergeInsertionVec(std::vector<int> input);
    std::vector<struct Pair> makePairsVec(std::vector<int> input);
    void insertPendChainVec(std::vector<int>& mainChain,
                            std::vector<int>& pendChain, size_t numPairs);

    // Deque Implementation
    std::deque<int> mergeInsertionDeq(std::deque<int> input);
    std::deque<struct Pair> makePairsDeq(std::deque<int> input);
    void insertPendChainDeq(std::deque<int>& mainChain,
                            std::deque<int>& pendChain, size_t numPairs);

    size_t m_counter;
    static bool m_debugEnabled;
};

// template functions implementation
template <typename Container>
void PmergeMe::printContainer(const Container& container,
                              const std::string& prefix,
                              const std::string& toPrint) {
    typename Container::const_iterator it;
    if (toPrint.empty() && !m_debugEnabled) {
        return;
    }
    if (!prefix.empty()) std::cout << CLR_YELLOW << prefix << " " << CLR_RESET;
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
Container PmergeMe::generateInsertionOrder(size_t pendSize) {
    Container order;

    if (pendSize == 0) return order;

    // First, always insert first element as it is always the smallest (as
    // pendChain[0] < mainChain[0])
    order.push_back(1);

    if (pendSize == 1) return order;

    size_t lastInserted = 1;  // We've conceptually covered up to b1 (1-based)

    // Jacbobsthal sequence to determine insertion order - starts at 3 as
    // J(1)=1, J(2)=1 (already covered)
    for (int k = 3;; k++) {
        size_t currJacob = jacobsthal(k);

        // Insert from min(currJacob, pendSize) down to lastInserted+1
        size_t high = currJacob;
        if (high > pendSize) {
            high = pendSize;
        }

        // Insert indices in descending order
        for (size_t index = high; index > lastInserted; index--) {
            order.push_back(index);
        }

        lastInserted = currJacob;

        if (currJacob >= pendSize) {
            break;
        }
    }

    return order;
}

template <typename Container>
void PmergeMe::processAndValidate(const std::string& typeName,
                                  const Container& input, Container& output,
                                  struct timeval& t1, struct timeval& t2) {
    // 1. Validate nb of comparisons
    printTime(typeName, t1, t2, input.size());
    std::cout << CLR_BLUE << "Number of comparisons with " << typeName << ": "
              << m_counter << CLR_RESET << std::endl;
    m_counter = 0;

    // 2. Validate sorting
    bool is_sorted = true;
    for (size_t i = 1; i < output.size(); i++) {
        if (output[i - 1] > output[i]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        dbgLog(CLR_GREEN, "SUCCESS", typeName + " is sorted");
    } else {
        dbgLog(CLR_MAGENTA, "FAIL", typeName + " is not sorted");
    }

    // 3.Validate output size
    if (input.size() == output.size()) {
        dbgLog(CLR_GREEN, "SUCCESS",
               "All numbers are present in the output " + typeName);
    } else {
        dbgLog(CLR_MAGENTA, "FAIL", "Missing numbers in the output" + typeName);
    }
}

#endif
