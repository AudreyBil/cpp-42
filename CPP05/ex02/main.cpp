/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:15:45 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 14:58:28 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime>

int main()
{
	std::cout << CYAN << BOLD << "\n==== Testing Shrubbery Creation Form ====\n" << RESET;

	{
	std::cout << CYAN << "\n*** Shrubbery Sign and Execution with Grade = 1 ***\n" << RESET;

	try {
		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery;
		Bureaucrat executor("executor", 1);
		executor.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << "\n*** Shrubbery Execution with Grade = 150 ***\n" << RESET;

	try {
		ShrubberyCreationForm shrubbery("Should not be created");
		std::cout << shrubbery;
		Bureaucrat executor("executor", 150);
		Bureaucrat chef("Chef", 1);
		chef.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << "\n==== Shrubbery Execution not signed ====\n" << RESET;

	try {
		ShrubberyCreationForm shrubbery("Should not be created");
		std::cout << shrubbery;
		Bureaucrat executor("executor", 1);
		executor.executeForm(shrubbery);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	srand(time(0));
	std::cout << CYAN << BOLD << "\n==== Testing Robotomy Creation Form ====\n" << RESET;

	{
	std::cout << CYAN << "\n*** Robotomy Sign and Execution with Grade = 1 ***\n" << RESET;

	try {
		RobotomyRequestForm robotomy("Ennemy");
		std::cout << robotomy;
		Bureaucrat executor("executor", 1);
		executor.signForm(robotomy);
		executor.executeForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << "\n*** Robotomy Execution with Grade = 150 ***\n" << RESET;

	try {
		RobotomyRequestForm robotomy("Ennemy");
		std::cout << robotomy;
		Bureaucrat executor("executor", 150);
		Bureaucrat chef("Chef", 1);
		chef.signForm(robotomy);
		executor.executeForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << "\n*** Robotomy Execution Not signed ***\n" << RESET;

	try {
		RobotomyRequestForm robotomy("Ennemy");
		std::cout << robotomy;
		Bureaucrat executor("executor", 1);
		executor.executeForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	std::cout << CYAN << BOLD << "\n==== Testing Presidential Pardon Form ====\n" << RESET;

	{
	std::cout << CYAN << "\n*** Presidential Pardon Sign and Execution with Grade = 1 ***\n" << RESET;

	try {
		PresidentialPardonForm presidential("Hitch Hiker");
		std::cout << presidential;
		Bureaucrat executor("executor", 1);
		executor.signForm(presidential);
		executor.executeForm(presidential);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << "\n*** Presidential Pardon Sign and Execution with Grade = 150 ***\n" << RESET;

	try {
		PresidentialPardonForm presidential("Hitch Hiker");
		std::cout << presidential;
		Bureaucrat executor("executor", 150);
		Bureaucrat chef("Chef", 1);
		chef.signForm(presidential);
		executor.executeForm(presidential);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << "\n*** Presidential Pardon Not Signed ***\n" << RESET;

	try {
		PresidentialPardonForm presidential("Hitch Hiker");
		std::cout << presidential;
		Bureaucrat executor("executor", 1);
		executor.executeForm(presidential);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << BOLD << "\n==== Testing Copy Constructor ====\n" << RESET;
	try {
		ShrubberyCreationForm original("original");
		ShrubberyCreationForm copy(original);
		std::cout << "Original: " << original;
		std::cout << "Copy: " << copy;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}

	{
	std::cout << CYAN << BOLD << "\n==== Testing Exact Grade Requirements ====\n" << RESET;
	try {
		ShrubberyCreationForm shrubbery("boundary");
		Bureaucrat signer("signer", 145);
		Bureaucrat executor("executor", 137);
		signer.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	}
}
