/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:00:37 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 12:12:36 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default constructor called\n";
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
};

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap "<< m_name << " constructed\n";
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
};

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called\n";
	*this = other;
}


FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment constructor called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->m_name = other.m_name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< m_name << " destroyed\n";;
}

void FragTrap::highFivesGuys(void)
{
	if (m_hitPoints <= 0)
	{
		std::cout << YELLOW << "FragTrap " << m_name << " is dead and cannot request a high five."
					<< RESET << "\n";
		return;
	}
	std::cout << GREEN << "FragTrap " << m_name << " enthusiastically requests high-fives from everyone! ✋"
				<< std::endl;
}
