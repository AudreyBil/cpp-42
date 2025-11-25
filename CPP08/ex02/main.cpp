/* ************************************************************************** */
/*	                                                                    */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:13:58 by abillote          #+#    #+#             */
/*   Updated: 2025/08/08 17:42:52 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>

#include "MutantStack.hpp"

#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

int main() {
    {
        std::cout << CYAN << BOLD << "Mutant Stack VS Deque\n" << RESET;
        MutantStack<int> mstack;
        std::deque<int> testDeque;

        std::cout << YELLOW << "Checking top\n" << RESET;
        mstack.push(5);
        mstack.push(17);
        std::cout << "MutantStack - top():" << mstack.top() << std::endl;

        testDeque.push_back(5);
        testDeque.push_back(17);
        std::cout << "Deque - back():" << testDeque.back() << std::endl;

        std::cout << YELLOW << std::endl
                  << "Checking size after pop\n"
                  << RESET;
        mstack.pop();
        std::cout << "MutantStack - size: " << mstack.size() << std::endl;

        testDeque.pop_back();
        std::cout << "Deque - size: " << testDeque.size() << std::endl;

        std::cout << YELLOW << BOLD << "\nMutant Stack iterator test:" << RESET
                  << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        int i = 0;
        while (it != ite) {
            std::cout << "Mutant Stack - number " << i << ": " << *it
                      << std::endl;
            ++it;
            i++;
        }
        std::stack<int> sStack(mstack);

        std::cout << YELLOW << BOLD << "\nDeque iterator test:" << RESET
                  << std::endl;
        testDeque.push_back(3);
        testDeque.push_back(5);
        testDeque.push_back(737);
        testDeque.push_back(0);
        std::deque<int>::iterator itDeque = testDeque.begin();
        std::deque<int>::iterator iteDeque = testDeque.end();
        ++itDeque;
        --itDeque;
        i = 0;
        while (itDeque != iteDeque) {
            std::cout << "Deque - number " << i << ": " << *itDeque
                      << std::endl;
            ++itDeque;
            i++;
        }

        {
            std::cout << CYAN << BOLD
                      << "\nMutant Stack constant iterator test:" << RESET
                      << std::endl;
            const MutantStack<int> constStack(mstack);
            MutantStack<int>::const_iterator itConst = constStack.begin();
            MutantStack<int>::const_iterator iteConst = constStack.end();
            int i = 0;
            while (itConst != iteConst) {
                std::cout << "Mutant Stack - number " << i << ": " << *itConst
                          << std::endl;
                ++itConst;
                i++;
            }
        }

        {
            std::cout << CYAN << BOLD
                      << "\nMutant Stack reverse iterator test:" << RESET
                      << std::endl;
            MutantStack<int> reverseStack(mstack);
            MutantStack<int>::reverse_iterator itReverse =
                reverseStack.rbegin();
            MutantStack<int>::reverse_iterator iteReverse = reverseStack.rend();
            int i = 0;

            while (itReverse != iteReverse) {
                std::cout << "Mutant Stack - number " << i << ": " << *itReverse
                          << std::endl;
                ++itReverse;
                i++;
            }
        }

        {
            std::cout << CYAN << BOLD << "\nMutant Stack - Testing find()"
                      << RESET << std::endl;
            MutantStack<int>::iterator found =
                std::find(mstack.begin(), mstack.end(), 5);
            if (found != mstack.end()) {
                std::cout << "Found element 5" << std::endl;
            }
        }

        {
            std::cout << CYAN << BOLD << "\nTest empty Mutant stack\n" << RESET;
            MutantStack<int> emptyStack;
            std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
            std::cout << "Empty stack empty?: "
                      << (emptyStack.empty() ? "true" : "false") << std::endl;

            // Test iterators on empty stack
            if (emptyStack.begin() == emptyStack.end()) {
                std::cout << "Empty stack: begin() == end() ✓" << std::endl;
            }
        }
    }

    return 0;
}
