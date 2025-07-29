/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:47:44 by abillote          #+#    #+#             */
/*   Updated: 2025/07/29 14:13:34 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
	public:
		AForm();
		AForm(const std::string name, const int gradeSigner, const int gradeExecuter);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName()const;
		int getGradeSigner() const;
		int getGradeExecuter() const;
		bool getIsSigned() const;

		void beSigned(Bureaucrat& bureaucrat);

		virtual void execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw ();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw ();
		};

	private:
		const std::string m_name;
		bool m_isSigned;
		const int m_gradeSigner;
		const int m_gradeExecuter;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif
