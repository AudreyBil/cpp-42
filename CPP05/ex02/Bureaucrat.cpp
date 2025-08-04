/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:44:22 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 14:46:50 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
: m_name("default"), m_grade(150)
{

};

Bureaucrat::Bureaucrat(const std::string name, int grade)
: m_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		m_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: m_name(other.m_name), m_grade(other.m_grade)
{

};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->m_grade = other.m_grade;
	return *this;
}


Bureaucrat::~Bureaucrat()
{

};

std::string Bureaucrat::getName() const
{
	return m_name;
}


int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::incrementGrade()
{
	if (m_grade == 1)
		throw GradeTooHighException();
	else
		m_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (m_grade == 150)
		throw GradeTooLowException();
	else
		m_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << this->getName() << " couldn't sign " << form.getName()
					<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << GREEN << BOLD << this->getName() << " executed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception &e){
		std::cout << RED << BOLD << this->getName() << " couldn't execute " << form.getName()
					<< " because " << e.what() << RESET << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade()
		<< ". \n";
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}
