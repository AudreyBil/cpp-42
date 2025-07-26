/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:17:19 by abillote          #+#    #+#             */
/*   Updated: 2025/07/23 17:58:08 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
:m_name("Unknown")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
};

Character::Character(const std::string& name)
: m_name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
};

Character::Character(const Character& other)
:m_name(other.m_name)
{
	for (int i = 0; i < 4; i++)
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
};

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
};

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
};

std::string const & Character::getName() const
{
	return m_name;
};

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full!\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	if (inventory[idx] == NULL)
		return;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (inventory[idx] == NULL)
		return;
	inventory[idx]->use(target);
}
