/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:25:21 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 21:45:33 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << DIM << "Brain constructed" << RESET << "\n";
};

Brain::Brain(const Brain& other)
{
	std::cout << GREEN << DIM << "Brain copy constructor called" << RESET << "\n";
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
}
Brain& Brain::operator=(const Brain& other)
{
	std::cout << GREEN << DIM << "Brain assignment operator called" << RESET << "\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << GREEN << DIM << "Brain has been destroyed" << RESET << "\n";
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

void Brain::printIdeas(int count) const
{
	for (int i = 0; i < count && i < 100; i++)
	{
		if (!ideas[i].empty())
			std::cout << "[" << i << "]: " << ideas[i] << "\n";
		}
}

void Brain::clearIdeas()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}
