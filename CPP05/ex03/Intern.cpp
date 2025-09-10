/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:01:47 by abillote          #+#    #+#             */
/*   Updated: 2025/09/08 13:21:11 by abillote         ###   ########.fr       */
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

AForm* Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
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

	AForm* (Intern::*formCreators[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential,
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << GREEN << BOLD << "Intern creates " << formName << RESET << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	throw Intern::FormDoesNotExist();
}
