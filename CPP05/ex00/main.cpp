/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:15:45 by abillote          #+#    #+#             */
/*   Updated: 2025/09/08 11:34:32 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "==== Testing Bureaucrat constructors && operator << overload ====\n\n";
	std::cout << "==== Grade = 1 ====\n";

	try {
		Bureaucrat bestEmployee("Julie", 1);
		std::cout << bestEmployee;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "==== Grade = 0 ====\n";

	try {
		Bureaucrat betterThanBestEmployee("Marina", 0);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "==== Grade = 151 ====\n";

	try {
		Bureaucrat WorseThanWorstEmployee("Philou", 151);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n==== Testing overload operator ====\n";
	Bureaucrat mediumEmployee("Bernard", 75);
	std::cout << mediumEmployee;

	std::cout << "\n==== Testing increment operator ====\n";
	std::cout << "==== Grade = 75 ====\n";
	try {
		mediumEmployee.incrementGrade();
		std::cout << mediumEmployee;
	}
	catch (const std::exception& e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "==== Grade = 1 ====\n";
	try {
		Bureaucrat bestEmployee("Julie", 1);
		bestEmployee.incrementGrade();
		std::cout << bestEmployee;
	}
	catch (const std::exception& e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n==== Testing decrement operator ====\n";
	std::cout << "==== Grade = 74 ====\n";
	try {
		mediumEmployee.decrementGrade();
		std::cout << mediumEmployee;
	}
	catch (const std::exception &e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "==== Grade = 150 ====\n";
	try {
		Bureaucrat worstEmployee("Julie", 150);
		worstEmployee.decrementGrade();
		std::cout << worstEmployee;
	}
	catch (const std::exception& e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
