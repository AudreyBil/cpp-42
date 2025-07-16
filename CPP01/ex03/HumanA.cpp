/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:49:20 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 17:40:41 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon& Weapon)
:name(""), weapon(Weapon)
{

};

HumanA::HumanA(std::string initialName, Weapon& Weapon)
:name(initialName), weapon(Weapon)
{

};

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
