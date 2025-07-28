/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:47:44 by abillote          #+#    #+#             */
/*   Updated: 2025/07/28 14:45:48 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(const std::string name, const int gradeSigner, const int gradeExecuter);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName()const;
		int getGradeSigner() const;
		int getGradeExecuter() const;
		bool getIsSigned() const;

		void beSigned(Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif
