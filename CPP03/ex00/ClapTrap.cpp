/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:27:33 by abillote          #+#    #+#             */
/*   Updated: 2025/07/20 13:39:03 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
: m_name(""), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called\n";
};

ClapTrap::ClapTrap(const std::string& name)
: m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap "<< m_name << " constructed\n";
};

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy constructor called\n";
	*this = other;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment constructor called\n";
	if (this != &other)
	{
		this->m_name = other.m_name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	return *this;
}

std::string ClapTrap::getName() const
{
	return m_name;
}

int ClapTrap::getHitPoints() const
{
	return m_hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return m_energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return m_attackDamage;
}

void ClapTrap::setName(std::string& name)
{
	m_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	m_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	m_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	m_attackDamage = attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap "<< m_name << " destroyed\n";;
}

void ClapTrap::attack(const std::string& target)
{
	if (m_energyPoints > 0 && m_hitPoints > 0)
	{
		std::cout << GREEN << "ClapTrap " << m_name << " attacks " << target << ", causing "
				<< m_attackDamage << " point" << (m_attackDamage != 1 ? "s":"")
				<< " of damage!" << RESET << "\n";
		m_energyPoints--;
	}
	else if (m_energyPoints <= 0)
		std::cout << YELLOW << "ClapTrap " << m_name << " has no energy to attack. Attack fails!"
					<< RESET << "\n";
	else if (m_hitPoints <= 0)
		std::cout << YELLOW << "ClapTrap " << m_name << " is dead and cannot attack."
					<< RESET << "\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hitPoints <= 0)
	{
		std::cout << DIM << RED "ClapTrap " << m_name << " is already dead and cannot take more damage."
					<< RESET << "\n";
		return;
	}
	m_hitPoints -= amount;
	if (m_hitPoints < 0)
		m_hitPoints = 0;
	if (m_hitPoints > 0)
	{
		std::cout << YELLOW << "ClapTrap " << m_name << " takes " << amount << " damage. "
					<< m_name << " has only "<< m_hitPoints << " hit points left." << RESET << "\n";
	}
	else if (m_hitPoints == 0)
	{
		std::cout << BOLD << RED << "ClapTrap " << m_name << " takes " << amount
					<< " damage and dies!" << RESET << "\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{

	if (m_energyPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap "<< m_name << " has no energy to repair itself." << RESET << "\n";
		return;
	}
	if(m_hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap "<< m_name << " is dead and cannot repair itself!"
					<< RESET << "\n";
		return;
	}
	if (m_hitPoints >= 10)
	{
		std::cout << MAGENTA << "ClapTrap " << m_name << " is already at full health (10 HP)!"
					<< RESET << "\n";
		return;
	}

	m_energyPoints--;
	m_hitPoints += amount;
	if (m_hitPoints > 10)
	{
		m_hitPoints = 10;
		std::cout << MAGENTA << "ClapTrap " << m_name << " repairs itself but hits the maximum health limit. "
					<< "Health capped at 10 HP!" << RESET << "\n";
	}
	else{
		std::cout << BRIGHT_GREEN << "ClapTrap " << m_name << " repairs itself by " << amount
					<< " hit points. "<< m_name << " has now " << m_hitPoints << " hit points and "
					<< m_energyPoints << " energy points." << RESET << "\n";
	}
}
