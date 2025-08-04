/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:48:07 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 14:43:52 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
: m_name("default"), m_isSigned(0), m_gradeSigner(1), m_gradeExecuter(1)
{

};

AForm::AForm(const std::string name, const int gradeSigner, const int gradeExecuter)
: m_name(name),  m_isSigned(0), m_gradeSigner(gradeSigner), m_gradeExecuter(gradeExecuter)
{
	if (m_gradeSigner < 1 || m_gradeExecuter < 1)
		throw (AForm::GradeTooHighException());
	else if (m_gradeSigner > 150 || m_gradeExecuter > 150)
		throw (AForm::GradeTooLowException());
};

AForm::AForm(const AForm& other)
: m_name(other.m_name), m_isSigned(other.m_isSigned), m_gradeSigner(other.m_gradeSigner), m_gradeExecuter(other.m_gradeExecuter)
{
	if (m_gradeSigner < 1 || m_gradeExecuter < 1)
		throw (AForm::GradeTooHighException());
	else if (m_gradeSigner > 150 || m_gradeExecuter > 150)
		throw (AForm::GradeTooLowException());
};

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		m_isSigned = other.m_isSigned; //We can only copy isSigned as the other members are constant
	return *this;
}

AForm::~AForm()
{

};

std::string AForm::getName()const
{
	return m_name;
}

int AForm::getGradeSigner() const
{
	return m_gradeSigner;
}
int AForm::getGradeExecuter() const
{
	return m_gradeExecuter;
}

bool AForm::getIsSigned() const
{
	return m_isSigned;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_gradeSigner)
		throw GradeTooLowException();
	else
		m_isSigned = 1;
}

void AForm::checkExecuteRequirement(Bureaucrat const& executor, int gradeExecutor) const
{
	if (getIsSigned() == 0)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeExecutor)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << AForm.getName() << " can be signed from Grade " << AForm.getGradeSigner()
		<< " and can be executed from Grade " << AForm.getGradeExecuter()
		<< "\nSigned? : " << AForm.getIsSigned() << std::endl;
	return (out);
}

const char* AForm::GradeTooHighException::what() const throw ()
{
	return "their grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return "their grade is too low.";
}

const char* AForm::FormNotSignedException::what() const throw ()
{
	return "the form must be signed before its execution.";
}
