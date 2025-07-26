/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:29:15 by abillote          #+#    #+#             */
/*   Updated: 2025/07/23 12:42:08 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called\n";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), m_name(name)
{
	std::cout << "DiamondTrap "<< m_name << " constructed\n";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), ScavTrap(other), FragTrap(other), m_name(other.m_name)
{
	std::cout << "DiamondTrap Copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy assignment constructor called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		m_name = other.m_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap "<< m_name << " destroyed\n";;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << GREEN << "My DiamondTrap name is " << m_name << RESET << "\n";
	std::cout << GREEN << "My ClapTrap name is " << ClapTrap::m_name << RESET << "\n";
}

