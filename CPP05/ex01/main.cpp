/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:15:45 by abillote          #+#    #+#             */
/*   Updated: 2025/07/28 14:49:53 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "==== Testing Form constructors ====\n";
	std::cout << "\n==== Grades in Correct Range ====\n";

	try {
		Form form1("Form1", 5, 3);
		std::cout << form1;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n==== Grades below correct Range ====\n";

	try {
		Form form1("Form1", 152, 3);
		std::cout << form1;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n==== Grades above correct Range ====\n";

	try {
		Form form1("Form1", 12, 0);
		std::cout << form1;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n==== Testing Signed function ====\n";

	Bureaucrat boss("Boss", 1);
	Form importantForm("Important", 1, 1);
	std::cout <<  importantForm;
	boss.signForm(importantForm);
	std::cout << importantForm;

	Bureaucrat employee("employee", 75);
	Form importantForm2("Important2", 1, 1);
	employee.signForm(importantForm2);
	std::cout << importantForm2;
}
