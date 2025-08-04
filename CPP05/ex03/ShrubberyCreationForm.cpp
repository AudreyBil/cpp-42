/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:28:40 by abillote          #+#    #+#             */
/*   Updated: 2025/08/02 15:11:22 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery Creation Form", 145, 137), m_target("default")
{

};
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("Shrubbery Creation Form", 145, 137), m_target(target)
{

};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), m_target(other.m_target)
{

};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{

};

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	AForm::checkExecuteRequirement(executor, 137);

	std::string filename = m_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Cannot create file: " + filename);

	file << "            .        +          .      .          .\n";
	file << "     .            _        .                    .\n";
	file << "  ,              /;-._,-.____        ,-----.__\n";
	file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n";
	file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n";
	file << "                      ,    `./  \\:. `.   )==-'  .\n";
	file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n";
	file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n";
	file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n";
	file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n";
	file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n";
	file << "              \\:  `  X` _| _,\\/'   .-'\n";
	file << ".               \":._:`\\____  /:'  /      .           .\n";
	file << "                    \\::.  :\\/:'  /              +\n";
	file << "   .                 `.:.  /:'  }      .\n";
	file << "           .           ):_(:;   \\           .\n";
	file << "                      /:. _/ ,  |\n";
	file << "                   . (|::.     ,`                  .\n";
	file << "     .                |::.    {\\\n";
	file << "                      |::.\\  \\ `.\n";
	file << "                      |:::(\\    |\n";
	file << "              O       |::/{\\}  |                  (o\n";
	file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n";
	file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n";
	file << "   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~\n";
	file << "\n";
	file << "                                     .\n";
	file << "                                   .         ;  \n";
	file << "      .              .              ;%     ;;   \n";
	file << "        ,           ,                :;%  %;   \n";
	file << "         :         ;                   :;%;'     .,   \n";
	file << ",.        %;     %;            ;        %;'    ,;\n";
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
	file << "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
	file << "     `%;.     ;%;     %;'         `;%%;.%;'\n";
	file << "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
	file << "         `:%;.  :;bd%;          %;@%;'\n";
	file << "           `@%:.  :;%.         ;@@%;'   \n";
	file << "             `@%.  `;@%.      ;@@%;         \n";
	file << "               `@%%. `@%%    ;@@%;        \n";
	file << "                 ;@%. :@%%  %@@%;       \n";
	file << "                   %@bd%%%bd%%:;     \n";
	file << "                     #@%%%%%:;;\n";
	file << "                     %@@%%%::;\n";
	file << "                     %@@@%(o);  . '         \n";
	file << "                     %@@@o%;:(.,'         \n";
	file << "                 `.. %@@@o%::;         \n";
	file << "                    `)@@@o%::;         \n";
	file << "                     %@@(o)::;        \n";
	file << "                    .%@@@@%::;         \n";
	file << "                    ;%@@@@%::;.          \n";
	file << "                   ;%@@@@%%:;;;. \n";
	file << "               ...;%@@@@@%%:;;;;,..\n";

	file.close();
}
