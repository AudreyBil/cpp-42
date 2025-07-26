/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:26:11 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 14:05:45 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:m_type("default")
{
	std::cout << GREEN << DIM << "WrongAnimal created with type = " << m_type << RESET << "\n";
};
WrongAnimal::WrongAnimal(std::string type)
:m_type(type)
{
	std::cout << GREEN << DIM << "WrongAnimal created with type = " << m_type << RESET << "\n";
};

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << GREEN << DIM << "WrongAnimal Copy Constructor called "<< RESET << "\n";
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << GREEN << DIM << "WrongAnimal Copy Assignment Operator called "<< RESET << "\n";
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << DIM << "WrongAnimal with type = " << m_type << " has been destroyed" << RESET << "\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << RED << "I am a WrongAnimal, I can not make any sound :(" << RESET << "\n";
}

std::string WrongAnimal::getType() const
{
	return m_type;
}
