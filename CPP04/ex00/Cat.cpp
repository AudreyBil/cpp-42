/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:49 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 14:18:07 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << YELLOW << DIM << "Cat created"<< RESET << "\n";
};
Cat::Cat(std::string type)
: Animal("Cat")
{
	(void)type;
	std::cout << YELLOW << DIM << "Cat created"<< RESET << "\n";
};

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << YELLOW << DIM << "Cat Copy Constructor called "<< RESET << "\n";
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << YELLOW << DIM << "Cat Copy Assignment Operator called "<< RESET << "\n";
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << YELLOW << DIM << "Cat has been destroyed" << RESET << "\n";
}

void Cat::makeSound() const
{
	std::cout << YELLOW << "MEEEOOOWW" << RESET << "\n";
}

