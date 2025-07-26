/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:49 by abillote          #+#    #+#             */
/*   Updated: 2025/07/23 14:41:35 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << YELLOW << DIM << "Cat created"<< RESET << "\n";
	m_brain = new Brain();
};
Cat::Cat(std::string type)
: Animal("Cat")
{
	(void)type;
	std::cout << YELLOW << DIM << "Cat created"<< RESET << "\n";
	m_brain = new Brain();
};

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << YELLOW << DIM << "Cat Copy Constructor called "<< RESET << "\n";
	m_brain = new Brain(*other.m_brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << YELLOW << DIM << "Cat Copy Assignment Operator called "<< RESET << "\n";
	if (this != &other)
	{
		m_type = other.m_type;
		// Deep copy the Brain content
		if (m_brain)
			delete m_brain;
		m_brain = new Brain(*other.m_brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << YELLOW << DIM << "Cat has been destroyed" << RESET << "\n";
}

void Cat::makeSound() const
{
	std::cout << YELLOW << "MEEEOOOWW" << RESET << "\n";
}

Brain* Cat::getBrain() const
{
	return m_brain;
}
