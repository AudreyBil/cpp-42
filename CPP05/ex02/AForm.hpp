/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:47:44 by abillote          #+#    #+#             */
/*   Updated: 2025/08/04 14:41:57 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

// Color definitions
#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define BOLD	"\033[1m"
#define DIM		"\033[2m"

// Bright colors
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_YELLOW	"\033[93m"

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
		void checkExecuteRequirement(Bureaucrat const& executor, int gradeExecutor) const;

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
		class FormNotSignedException : public std::exception
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
