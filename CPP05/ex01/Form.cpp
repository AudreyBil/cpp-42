/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:48:07 by abillote          #+#    #+#             */
/*   Updated: 2025/07/28 14:49:09 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
: m_name("default"), m_isSigned(0), m_gradeSigner(1), m_gradeExecuter(1)
{

};

Form::Form(const std::string name, const int gradeSigner, const int gradeExecuter)
: m_name(name),  m_isSigned(0), m_gradeSigner(gradeSigner), m_gradeExecuter(gradeExecuter)
{
	if (m_gradeSigner < 1 || m_gradeExecuter < 1)
		throw (Form::GradeTooHighException());
	else if (m_gradeSigner > 150 || m_gradeExecuter > 150)
		throw (Form::GradeTooLowException());
};

Form::Form(const Form& other)
: m_name(other.m_name), m_isSigned(other.m_isSigned), m_gradeSigner(other.m_gradeSigner), m_gradeExecuter(other.m_gradeExecuter)
{
	if (m_gradeSigner < 1 || m_gradeExecuter < 1)
		throw (Form::GradeTooHighException());
	else if (m_gradeSigner > 150 || m_gradeExecuter > 150)
		throw (Form::GradeTooLowException());
};

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		m_isSigned = other.m_isSigned;
	return *this;
}

Form::~Form()
{

};

std::string Form::getName()const
{
	return m_name;
}

int Form::getGradeSigner() const
{
	return m_gradeSigner;
}
int Form::getGradeExecuter() const
{
	return m_gradeExecuter;
}

bool Form::getIsSigned() const
{
	return m_isSigned;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_gradeSigner)
		throw GradeTooLowException();
	else
		m_isSigned = 1;
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << Form.getName() << ", can be signed from Grade" << Form.getGradeSigner()
		<< " and can be executed from Grade " << Form.getGradeExecuter()
		<< "\nSigned? : " << Form.getIsSigned() << std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what() const throw ()
{
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return "Grade is too low.";
}
