/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:47:52 by abillote          #+#    #+#             */
/*   Updated: 2025/07/17 11:41:58 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain (std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int indexLevel = 5;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			indexLevel = i;
			break ;
		}
	}

	switch (indexLevel){
		case 0:
			std::cout << "[ DEBUG ]\n";
			debug();
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]\n";
			info();
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]\n";
			warning();
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]\n";
			error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
	<< "pickle-special-ketchup burger. \nI really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. \n"
	<< "You didn’t put enough bacon in my burger!\n"
	<< "If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
	<< "I’ve been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

