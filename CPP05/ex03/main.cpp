/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:15:45 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 16:00:14 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main()
{
	srand(time(0));

	std::cout << CYAN << BOLD << "\n==== Testing Shrubbery Creation Form by Intern ====\n" << RESET;

	{
	try {
		Intern randomIntern;
		AForm* shrubbery = randomIntern.makeForm("Shrubbery creation", "home");
		std::cout << *shrubbery;
		Bureaucrat executor("executor", 1);
		executor.signForm(*shrubbery);
		executor.executeForm(*shrubbery);
		delete shrubbery;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	std::cout << CYAN << BOLD << "\n==== Testing Robotomy Request Form by Intern ====\n" << RESET;

	{
	try {
		Intern randomIntern;
		AForm* robotomy = randomIntern.makeForm("Robotomy request", "Ennemy");
		std::cout << *robotomy;
		Bureaucrat executor("executor", 1);
		executor.signForm(*robotomy);
		executor.executeForm(*robotomy);
		delete robotomy;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	std::cout << CYAN << BOLD << "\n==== Testing Presidential Pardon Form by Intern ====\n" << RESET;

	{
	try {
		Intern randomIntern;
		AForm* presidential = randomIntern.makeForm("Presidential pardon", "Hitch Hiker");
		std::cout << *presidential;
		Bureaucrat executor("executor", 1);
		executor.signForm(*presidential);
		executor.executeForm(*presidential);
		delete presidential;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	std::cout << CYAN << BOLD << "\n==== Testing Unknown Form ====\n" << RESET;

	{
	try {
		Intern randomIntern;
		AForm* unknown = randomIntern.makeForm("unknown", "random");
		std::cout << *unknown;
		Bureaucrat executor("executor", 1);
		executor.signForm(*unknown);
		executor.executeForm(*unknown);
		delete unknown;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << BOLD << "\n==== Testing Multiple Forms from Same Intern ====\n" << RESET;
	try {
		Intern intern;
		AForm* forms[3] = {
			intern.makeForm("Shrubbery creation", "garden1"),
			intern.makeForm("Robotomy request", "robot1"),
			intern.makeForm("Presidential pardon", "prisoner1")
		};

		for (int i = 0; i < 3; i++) {
			if (forms[i]) {
				std::cout << *forms[i];
				delete forms[i];
			}
		}
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

}
