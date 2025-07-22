/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:16 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 14:02:33 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
:m_type("default")
{
	std::cout << GREEN << DIM << "Animal created with type = " << m_type << RESET << "\n";
};
Animal::Animal(std::string type)
:m_type(type)
{
	std::cout << GREEN << DIM << "Animal created with type = " << m_type << RESET << "\n";
};

Animal::Animal(const Animal& other)
{
	std::cout << GREEN << DIM << "Animal Copy Constructor called "<< RESET << "\n";
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << GREEN << DIM << "Animal Copy Assignment Operator called "<< RESET << "\n";
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << GREEN << DIM << "Animal with type = " << m_type << " has been destroyed" << RESET << "\n";
}

void Animal::makeSound() const
{
	std::cout << RED << "I am an Animal without type, I can not make any sound :(" << RESET << "\n";
}

std::string Animal::getType() const
{
	return m_type;
}
