/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:48:32 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 17:07:37 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
: type("")
{

};

Weapon::Weapon(std::string initialType)
: type(initialType)
{

};

std::string Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string newtype)
{
	type = newtype;
}
