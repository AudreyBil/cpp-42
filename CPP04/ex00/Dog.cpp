/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:33 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 14:18:32 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << MAGENTA << DIM << "Dog created"<< RESET << "\n";
};
Dog::Dog(std::string type)
: Animal("Dog")
{
	(void)type;
	std::cout << MAGENTA << DIM << "Dog created"<< RESET << "\n";
};

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << MAGENTA << DIM << "Dog Copy Constructor called "<< RESET << "\n";
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << MAGENTA << DIM << "Dog Copy Assignment Operator called "<< RESET << "\n";
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << MAGENTA << DIM << "Dog has been destroyed" << RESET << "\n";
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << "WOUF WOUF!" << RESET << "\n";
}
