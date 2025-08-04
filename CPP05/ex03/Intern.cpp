/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:01:47 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 15:55:27 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

};

Intern::Intern(const Intern& /*other*/)
{

};

Intern& Intern::operator=(const Intern& /*other*/)
{
	return *this;
}


Intern::~Intern()
{

};

static AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

const char* Intern::FormDoesNotExist::what() const throw ()
{
	return "This form name does not exist!";
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {
		"Shrubbery creation",
		"Robotomy request",
		"Presidential pardon"
	};

	AForm* (*formCreators[3])(std::string) = {
		createShrubbery,
		createRobotomy,
		createPresidential,
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << GREEN << BOLD << "Intern creates " << formName << RESET << std::endl;
			return formCreators[i](target);
		}
	}
	throw Intern::FormDoesNotExist();
}
