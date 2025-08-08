/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:13:58 by abillote          #+#    #+#             */
/*   Updated: 2025/08/08 18:05:18 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define CYAN	"\033[36m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"

void increment(int& nb)
{
	nb++;
	std::cout << "Printing the array element after incrementation: " << nb << std::endl;
}

int main( void ) {

	{
	std::cout << CYAN << BOLD << "--- Test integers array with an instantiated function template---" << RESET << std::endl;
	int intArray[3] = {1, 2, 3};
	::iter(intArray, 3, printNonConst<int>);

	const int intArrayConst[3] = {4, 5, 6};
	::iter(intArrayConst, 3, printConst<int>);
	}
	{
	std::cout << CYAN << BOLD << "\n---Test integers array with a function---" << RESET << std::endl;
	int intArray[3] = {1, 2, 3};
	::iter(intArray, 3, increment);
	}
	{
	std::cout << CYAN << BOLD << "\n--- Test char array  with an instantiated function template---" << RESET << std::endl;
	char charArray[3] = {'a', 'b', 'c'};
	::iter(charArray, 3, printNonConst<char>);

	const char charArrayConst[3] = {'d', 'e', 'f'};
	::iter(charArrayConst, 3, printConst<char>);
	}
	{
	std::cout << CYAN << BOLD << "\n--- Test string array---" << RESET << std::endl;
	char modifiableString[] = "Hello";
	::iter(modifiableString, 3, printNonConst<char>);

	const char *constString = "Hey";
	::iter(constString, 3, printConst<char>);
	}

	{
	std::cout << CYAN << BOLD << "\n--- Test empty array ---" << RESET << std::endl;
	int* emptyArray = nullptr;
	::iter(emptyArray, 0, printConst<int>);
}

	return 0;
}


