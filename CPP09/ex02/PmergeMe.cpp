// Test with random numbers: `shuf -i 1-100000 -n 87 | tr "\n" " "`

#include "PmergeMe.hpp"

#include <algorithm>
#include <cmath>

bool PmergeMe::m_debugEnabled = false;

// ==================== PUBLIC UTILITIES ====================

void PmergeMe::dbgLog(const char* color, const std::string& tag,
                      const std::string& msg) {
    if (!m_debugEnabled) return;
    std::cerr << color << "[" << tag << "] " << msg << CLR_RESET << std::endl;
}

int fordJohnsonMaxComparisons(int n) {
    int sum = 0;
    for (int k = 1; k <= n; k++) {
        sum += static_cast<int>(
            std::ceil(std::log(3.0 * k / 4.0) / std::log(2.0)));
    }
    return sum;
}

static std::string toStr(int v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

static std::string toStr(size_t v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

// ==================== CONSTRUCTORS ====================

PmergeMe::PmergeMe() : m_counter(0){};

PmergeMe::PmergeMe(const PmergeMe& other) : m_counter(other.m_counter) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) *this = other;
    return *this;
}

PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(std::vector<int> input) : m_counter(0) {
    struct timeval t1;
    struct timeval t2;

    // Vector
    printContainer(input, "Before:", "true");
    gettimeofday(&t1, NULL);
    std::vector<int> outputVec = mergeInsertionVec(input);
    gettimeofday(&t2, NULL);
    printContainer(outputVec, "After:", "true");
    processAndValidate<std::vector<int> >("vector", input, outputVec, t1, t2);

    // Deque
    std::deque<int> inputDeq(input.begin(), input.end());
    gettimeofday(&t1, NULL);
    std::deque<int> outputDeq = mergeInsertionDeq(inputDeq);
    gettimeofday(&t2, NULL);
    processAndValidate<std::deque<int> >("deque", inputDeq, outputDeq, t1, t2);

    // Max comparisons
    std::cout << CLR_BLUE << "Ford-Johnson max comparisons for " << input.size()
              << " elements: " << fordJohnsonMaxComparisons(input.size())
              << CLR_RESET << std::endl;
};

// ==================== VECTOR IMPLEMENTATION ====================

std::vector<int> PmergeMe::mergeInsertionVec(std::vector<int> input) {
    //----Base case: end of recursion----//
    if (input.size() <= 1) {
        dbgLog(CLR_YELLOW, "Base Case", "Only one member in Main Chain");
        return input;
    }

    //----If odd numbers: remove the last one and store it----//
    int stagger = -1;
    if (input.size() % 2 != 0) {
        stagger = input.back();
        input.pop_back();
    }

    //----Step 1 : Making Pairs----//
    std::vector<Pair> pairs = makePairsVec(input);
    std::vector<int> mainChain;
    std::vector<int> pendChain;

    dbgLog(CLR_MAGENTA, "Step",
           "Pushing highest pair members in Main Chain and lowest in Pending "
           "Chain");
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].highest);
        pendChain.push_back(pairs[i].lowest);
    }

    dbgLog(CLR_YELLOW, "Main Chain", "");
    printContainer(mainChain);
    dbgLog(CLR_YELLOW, "Pending Chain", "");
    printContainer(pendChain);

    //----Step 2 : Recursively sort largest numbers----//
    dbgLog(CLR_CYAN, "Recursion", "Entering Main Chain recursion");

    // Sort the main chain recursively
    mainChain = mergeInsertionVec(mainChain);

    dbgLog(CLR_CYAN, "Recursion", "Leaving recursion");

    //----Step 3: Realign pendChain to match the new mainChain order
    std::vector<int> realignedPend;
    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].highest == mainChain[i]) {
                realignedPend.push_back(pairs[j].lowest);
                break;
            }
        }
    }
    pendChain = realignedPend;

    dbgLog(CLR_YELLOW, "Realigned Pending Chain to match new mainChain order",
           "");
    printContainer(pendChain);

    // Now pendChain[i] < mainChain[i] for all i < mainChain.size()
    size_t numPairs = mainChain.size();

    //----If stagger - add it to Pending Chain----//
    if (stagger >= 0) {
        dbgLog(CLR_YELLOW, "Stagger", "Adding Stagger to Pending Chain");
        pendChain.push_back(stagger);
        dbgLog(CLR_YELLOW, "Pending Chain", "");
        printContainer(pendChain);
    }

    //----Step 4: Insert Pending numbers into Main Chain----//
    insertPendChainVec(mainChain, pendChain, numPairs);

    return mainChain;
}

std::vector<PmergeMe::Pair> PmergeMe::makePairsVec(std::vector<int> input) {
    std::vector<Pair> pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        Pair p;
        m_counter++;
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
        dbgLog(CLR_YELLOW, "Pair " + toStr(i),
               toStr(pairs[i].lowest) + "-" + toStr(pairs[i].highest));
    }

    return pairs;
}

void PmergeMe::insertPendChainVec(std::vector<int>& mainChain,
                                  std::vector<int>& pendChain,
                                  size_t numPairs) {
    dbgLog(CLR_MAGENTA, "Step", "Inserting Pending Chain into Main Chain");
    dbgLog(CLR_YELLOW, "Main Chain", "");
    printContainer(mainChain);
    dbgLog(CLR_YELLOW, "Pending Chain", "");
    printContainer(pendChain);

    if (pendChain.empty()) {
        return;
    }

    // Generate the insertion order using Jacobsthal sequence
    std::vector<size_t> insertionOrder =
        generateInsertionOrder<std::vector<size_t> >(pendChain.size());

    dbgLog(CLR_MAGENTA, "Step", "Generating Insertion order:");
    printContainer(insertionOrder);

    // Track positions of original mainChain elements as we insert (as numbers
    // will shift)
    std::vector<size_t> positionOf(numPairs);
    for (size_t i = 0; i < numPairs; i++) {
        positionOf[i] = i;
    }

    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t pendIndex = insertionOrder[i] - 1;  // Convert to 0-based index

        if (pendIndex >= pendChain.size()) {
            continue;
        }

        int toInsert = pendChain[pendIndex];

        // Calculate the search bound
        size_t bound;
        if (pendIndex < numPairs) {
            // The bound is the current position of the paired element
            bound = positionOf[pendIndex];
        } else {
            // Stagger - search entire chain
            bound = mainChain.size();
        }

        dbgLog(CLR_CYAN, "Insert",
               "Inserting element: " + toStr(toInsert) + " (pendIndex: " +
                   toStr(pendIndex) + ", bound: " + toStr(bound) + ")");

        // Binary search within [0, bound]
        size_t start = 0;
        size_t end = bound;
        while (start < end) {
            size_t mid = start + (end - start) / 2;
            m_counter++;
            if (mainChain[mid] < toInsert) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        // Insert at position 'start'
        mainChain.insert(mainChain.begin() + start, toInsert);

        // Update all position trackers for elements that shifted right
        for (size_t j = 0; j < numPairs; j++) {
            if (positionOf[j] >= start) {
                positionOf[j]++;
                dbgLog(CLR_CYAN, "Position Update",
                       "Element at pair index " + toStr(j) +
                           " shifted to position " + toStr(positionOf[j]));
            }
        }
        dbgLog(CLR_YELLOW, "Position Of PendChain Pair Index in Main Chain",
               "");
        printContainer(positionOf);

        dbgLog(CLR_YELLOW, "Main Chain after insert", "");
        printContainer(mainChain);
    }
}

// ==================== DEQUE IMPLEMENTATION ====================

std::deque<int> PmergeMe::mergeInsertionDeq(std::deque<int> input) {
    //----Base case: end of recursion----//
    if (input.size() <= 1) {
        return input;
    }

    //----If odd numbers: remove the last one and store it----//
    int stagger = -1;
    if (input.size() % 2 != 0) {
        stagger = input.back();
        input.pop_back();
    }

    //----Step 1 : Making Pairs----//
    std::deque<Pair> pairs = makePairsDeq(input);
    std::deque<int> mainChain;
    std::deque<int> pendChain;

    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].highest);
        pendChain.push_back(pairs[i].lowest);
    }

    //----Step 2 : Recursively sort largest numbers----//
    mainChain = mergeInsertionDeq(mainChain);

    //----Step 3: Realign pendChain to match the new mainChain order
    std::deque<int> realignedPend;
    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].highest == mainChain[i]) {
                realignedPend.push_back(pairs[j].lowest);
                break;
            }
        }
    }
    pendChain = realignedPend;

    // Now pendChain[i] < mainChain[i] for all i < mainChain.size()
    size_t numPairs = mainChain.size();

    //----If stagger - add it to Pending Chain----//
    if (stagger >= 0) {
        pendChain.push_back(stagger);
    }

    //----Step 4: Insert Pending numbers into Main Chain----//
    insertPendChainDeq(mainChain, pendChain, numPairs);

    return mainChain;
}

std::deque<PmergeMe::Pair> PmergeMe::makePairsDeq(std::deque<int> input) {
    std::deque<Pair> pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        Pair p;
        m_counter++;
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

void PmergeMe::insertPendChainDeq(std::deque<int>& mainChain,
                                  std::deque<int>& pendChain, size_t numPairs) {
    if (pendChain.empty()) {
        return;
    }

    // Generate the insertion order using Jacobsthal sequence
    std::deque<size_t> insertionOrder =
        generateInsertionOrder<std::deque<size_t> >(pendChain.size());

    // Track positions of original mainChain elements as we insert (as numbers
    // will shift)
    std::deque<size_t> positionOf(numPairs);
    for (size_t i = 0; i < numPairs; i++) {
        positionOf[i] = i;
    }

    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t pendIndex = insertionOrder[i] - 1;  // Convert to 0-based index

        if (pendIndex >= pendChain.size()) {
            continue;
        }

        int toInsert = pendChain[pendIndex];

        // Calculate the search bound
        size_t bound;
        if (pendIndex < numPairs) {
            // The bound is the current position of the paired element
            bound = positionOf[pendIndex];
        } else {
            // Stagger - search entire chain
            bound = mainChain.size();
        }

        // Binary search within [0, bound]
        size_t start = 0;
        size_t end = bound;
        while (start < end) {
            size_t mid = start + (end - start) / 2;
            m_counter++;
            if (mainChain[mid] < toInsert) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        // Insert at position 'start'
        mainChain.insert(mainChain.begin() + start, toInsert);

        // Update all position trackers for elements that shifted right
        for (size_t j = 0; j < numPairs; j++) {
            if (positionOf[j] >= start) {
                positionOf[j]++;
            }
        }
    }
}

// ==================== UTILITIES ====================

// Jacbostahl number calculation
size_t PmergeMe::jacobsthal(int n) {
    // Implementing mathematical formula with iterative approach
    // J(n) = J(n - 1) + 2 * J(n-2) with base case J(0) = 0, J(1) = 1
    size_t prev2 = 0;
    size_t prev1 = 1;
    for (int i = 2; i <= n; i++) {
        size_t curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// Time Utility functions
void PmergeMe::printTime(const std::string& containerType, struct timeval& ts1,
                         struct timeval& ts2, size_t inputSize) {
    std::cout << CLR_MAGENTA << "Time to process a range of " << inputSize
              << " elements with std::" << containerType << ": " << CLR_RESET;
    displayTime(ts1, ts2);
}

void PmergeMe::displayTime(struct timeval& ts1, struct timeval& ts2) {
    size_t totalusects1 = ts1.tv_sec * 1000000 + ts1.tv_usec;
    size_t totalusects2 = ts2.tv_sec * 1000000 + ts2.tv_usec;
    size_t diff = totalusects2 - totalusects1;

    size_t seconds = diff / 1000000;
    size_t milliseconds = (diff % 1000000) / 1000;
    size_t microseconds = diff % 1000;
    std::cout << seconds << "s " << milliseconds << "ms " << microseconds
              << "us" << std::endl;
}
