/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:33 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 21:34:17 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << MAGENTA << DIM << "Dog created"<< RESET << "\n";
	m_brain = new Brain();
};

Dog::Dog(std::string type)
: Animal("Dog")
{
	(void)type;
	std::cout << MAGENTA << DIM << "Dog created"<< RESET << "\n";
	m_brain = new Brain();
};

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << MAGENTA << DIM << "Dog Copy Constructor called "<< RESET << "\n";
	m_brain = new Brain();
	*m_brain = *(other.m_brain);  // Deep copy the Brain content instead of pointing to same memory
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << MAGENTA << DIM << "Dog Copy Assignment Operator called "<< RESET << "\n";
	if (this != &other)
	{
		m_type = other.m_type;
		if (m_brain)
			delete m_brain; //Delete existing brain
		m_brain = new Brain(); // Create a new brain
		*m_brain = *(other.m_brain); //Deep copy the brain content
	}
	return *this;
}

Dog::~Dog()
{
	delete m_brain;  // Clean up the Brain pointer
	std::cout << MAGENTA << DIM << "Dog has been destroyed" << RESET << "\n";
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << "WOUF WOUF!" << RESET << "\n";
}

Brain* Dog::getBrain() const
{
	return m_brain;
}
