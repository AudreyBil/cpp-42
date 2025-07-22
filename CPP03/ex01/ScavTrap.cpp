/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:44:51 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 10:38:42 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default constructor called\n";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
};

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap "<< m_name << " constructed\n";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
};

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";
	*this = other;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment constructor called\n";
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap "<< m_name << " destroyed\n";;
}

void ScavTrap::guardGate()
{
	if (m_hitPoints <= 0)
	{
		std::cout << YELLOW << "ScavTrap " << m_name << " is dead and cannot guard the gate."
					<< RESET << "\n";
		return;
	}
	std::cout << GREEN << "ScavTrap " << m_name << " is now in Gate Keeper mode!" << RESET << "\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (m_energyPoints > 0 && m_hitPoints > 0)
	{
		std::cout << GREEN << "ScavTrap " << m_name << " attacks " << target << ", causing "
				<< m_attackDamage << " point" << (m_attackDamage != 1 ? "s":"")
				<< " of damage!" << RESET << "\n";
		m_energyPoints--;
	}
	else if (m_energyPoints <= 0)
		std::cout << YELLOW << "ScavTrap " << m_name << " has no energy to attack. Attack fails!"
					<< RESET << "\n";
	else if (m_hitPoints <= 0)
		std::cout << YELLOW << "ScavTrap " << m_name << " is dead and cannot attack."
					<< RESET << "\n";
}
