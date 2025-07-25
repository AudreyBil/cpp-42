/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:26:19 by abillote          #+#    #+#             */
/*   Updated: 2025/07/25 10:52:04 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << YELLOW << DIM << "WrongCat created"<< RESET << "\n";
};
WrongCat::WrongCat(std::string type)
:WrongAnimal("WrongCat")
{
	(void)type;
	std::cout << YELLOW << DIM << "WrongCat created"<< RESET << "\n";
};

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << YELLOW << DIM << "WrongCat Copy Constructor called "<< RESET << "\n";
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << YELLOW << DIM << "WrongCat Copy Assignment Operator called "<< RESET << "\n";
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << DIM << "WrongCat has been destroyed" << RESET << "\n";
}

void WrongCat::makeSound() const
{
	std::cout << YELLOW << "MEEEOOOWW" << RESET << "\n";
}
