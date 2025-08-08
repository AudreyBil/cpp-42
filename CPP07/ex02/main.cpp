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

#include "Array.hpp"

#define CYAN	"\033[36m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"


int main( void ) {

	{
	std::cout << CYAN << BOLD << "\n--- Test empty array---" << RESET << std::endl;
	Array<int> intArray;
	std::cout << "Empty array size is :" << intArray.size() << std::endl;

	std::cout << CYAN << BOLD << "\n---Test out of bounds---" << RESET << std::endl;
	try {
	std::cout << "Trying to access index 1 of an empty array: " << intArray[5] << std::endl;
	} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << BOLD << "\n---Testconst array---" << RESET << std::endl;
	const Array<int> intArray(9);
	std::cout << "Const array size is :\n" << intArray.size() << std::endl;
	}
	{
	std::cout << CYAN << BOLD << "\n---Test char array---" << RESET << std::endl;
	Array<char> charArray(6);
	charArray[0] = 'a';
	try {
		std::cout << "Accessing index 0 (should be 'a'): " << charArray[0] << std::endl;
	} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
	}
	}
	{
	std::cout << CYAN << BOLD << "\n---Test copy constructor---" << RESET << std::endl;
	Array<int> originalArray(6);
	originalArray[0] = 1;
	Array<int> copyArray(originalArray);
	try {
		std::cout << "Accessing index 0 of original array : " <<originalArray[0] << std::endl;
		std::cout << "Accessing index 0 of copy array : " <<copyArray[0] << std::endl;
		std::cout << BOLD << "Modifying index 0 of original array" << RESET<< std::endl;
		originalArray[0] = 2;
		std::cout << "Accessing index 0 of original array : " <<originalArray[0] << std::endl;
		std::cout << "Accessing index 0 of copy array : " <<copyArray[0] << std::endl;

	} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
	}
	}
	{
	std::cout << CYAN << BOLD << "\n---Test copy assignement operator---" << RESET << std::endl;
	Array<int> originalArray(6);
	originalArray[0] = 1;
	Array<int> copyArray(2);
	copyArray[0] = 2;
	copyArray = originalArray;
	try {
		std::cout << "Accessing index 0 of original array : " <<originalArray[0] << std::endl;
		std::cout << "Accessing index 0 of copy array : " <<copyArray[0] << std::endl;
		std::cout << "Size of original array: " << originalArray.size() << std::endl;
		std::cout << "Size of copy array: " << copyArray.size() << std::endl;
		std::cout << BOLD << "Modifying index 0 of original array" << RESET<< std::endl;
		originalArray[0] = 2;
		std::cout << "Accessing index 0 of original array : " <<originalArray[0] << std::endl;
		std::cout << "Accessing index 0 of copy array : " <<copyArray[0] << std::endl;

	} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
	}
	}
	 {
	std::cout << CYAN << BOLD << "\n--- Test different types ---" << RESET << std::endl;

	Array<std::string> stringArray(2);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	std::cout << "String array: " << stringArray[0] << " " << stringArray[1] << std::endl;

	Array<float> floatArray(3);
	floatArray[0] = 1.1f;
	floatArray[1] = 2.2f;
	floatArray[2] = 3.3f;
	std::cout << "Float array: " << floatArray[0] << ", " << floatArray[1] << ", " << floatArray[2] << std::endl;
	}
	return 0;
}
