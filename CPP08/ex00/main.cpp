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

#include "easyfind.hpp"
#include <list>

#define CYAN	"\033[36m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"


int main(void) {

	std::vector<int> arr;
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(3);

	std::vector<int>::const_iterator it = arr.end();

	std::cout << CYAN << BOLD << "---Test existing int---" << RESET << std::endl;
	try {
		it = ::easyfind(arr, 4);
		std::cout << *it << " was found\n";
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << CYAN << BOLD << "\n---Test non-existing int---" << RESET << std::endl;

	try {
		it = ::easyfind(arr, 9);
		std::cout << *it << " was found\n";
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << CYAN << BOLD << "\n---Test empty container---" << RESET << std::endl;
	std::vector<int> empty;
	try {
		it = ::easyfind(empty, 9);
		std::cout << *it << " was found\n";
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << CYAN << BOLD << "\n---Test wit std::list ---" << RESET << std::endl;
	std::list<int> myList;
	myList.push_back(1);
	myList.push_back(5);
	std::list<int>::const_iterator itList;
	try {
		itList = ::easyfind(myList, 5);
		std::cout << *itList << " was found\n";
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
