/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:29:46 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 14:55:06 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon Form", 25, 5), m_target("default")
{

};
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("Presidential Pardon Form", 25, 5), m_target(target)
{

};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), m_target(other.m_target)
{

};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm()
{

};

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	AForm::checkExecuteRequirement(executor, 5);

	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
