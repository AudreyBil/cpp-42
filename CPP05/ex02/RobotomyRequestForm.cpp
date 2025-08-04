/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:01:18 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 14:54:50 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy Request Form", 72, 45), m_target("default")
{

};
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("Robotomy Request Form", 72, 45), m_target(target)
{

};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), m_target(other.m_target)
{

};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm()
{

};

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	AForm::checkExecuteRequirement(executor, 45);

	std::cout << "Vrrrr zzzz Vrrrrr zzzz\n";

	int robotomized = rand() % 2;
	if (robotomized)
		std::cout << m_target << " has been successfully robotomized.\n";
	else
		std::cout << "Robotomy of " << m_target << " failed.\n";
}
