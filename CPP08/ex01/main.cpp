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

#include "Span.hpp"

#define CYAN	"\033[36m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"


int main()
{
	{
	std::cout << CYAN << BOLD << "---Testing simple Span with 5 integers---" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Storage contains " << sp.getSize() << " integers\n";
	std::cout << "Shortest span is : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span is : " << sp.longestSpan() << std::endl;
	}

	{
	std::cout << CYAN << BOLD << "\n--- Testing 20000 Random Integers ---" << RESET << std::endl;

	Span sp(20000);
	std::vector<int> randomNumbers;

	std::srand(time(0));

	for (int i = 0; i < 20000; ++i) {
		int randomNum = std::rand() % 100000 + 1;
		randomNumbers.push_back(randomNum);
	}

	sp.addRange(randomNumbers.begin(), randomNumbers.end());

	if (sp.getSize() == 20000)
		std::cout << BOLD << "✓ Successfully added 20000 random integers" << RESET << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	{
	std::cout << CYAN << BOLD << "\n---Testing empty array---" << RESET << std::endl;
	Span sp = Span(5);
	try {
	std::cout << "Storage contains " << sp.getSize() << " integers\n";
	std::cout << "Shortest span is : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span is : " << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	};
	}

	{
	std::cout << CYAN << BOLD << "\n---Testing array with 1 int---" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(1);
	try {
	std::cout << "Storage contains " << sp.getSize() << " integers\n";
	std::cout << "Shortest span is : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span is : " << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	};
	}

	{
	std::cout << CYAN << BOLD << "\n---Testing addRange with C_style array---" << RESET << std::endl;

	Span sp(10);

	// Test with array
	int arr[] = {1, 2, 3, 4, 5};
	sp.addRange(arr, arr + 5);
	std::cout << "Added array: size = " << sp.getSize() << std::endl;
	std::cout << "Shortest span is : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span is : " << sp.longestSpan() << std::endl;
	}

	{
	std::cout << CYAN << BOLD << "\n---Testing storage overflow---" << RESET << std::endl;

	Span sp(3);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);

	try {
		sp.addNumber(4);
	} catch (std::exception& e) {
		std::cout << "Expected overflow: " << e.what() << std::endl;
	}

	// Test addRange overflow
	std::vector<int> tooMany;
	tooMany.push_back(10);
	tooMany.push_back(20);
	try {
		sp.addRange(tooMany.begin(), tooMany.end());  // Should throw
	} catch (std::exception& e) {
		std::cout << "Expected range overflow: " << e.what() << std::endl;
	}
	}

	return 0;
}
