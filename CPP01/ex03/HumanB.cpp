/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:50:51 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 17:42:00 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB()
:name(""), weapon(NULL)
{

};

HumanB::HumanB(std::string initialName)
:name(initialName), weapon(NULL)
{

};

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
