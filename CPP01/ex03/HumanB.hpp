/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:50:59 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 17:44:25 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class Weapon;

class HumanB
{
	public:
		HumanB();
		HumanB(std::string initialName);
		void setWeapon(Weapon& newWeapon);
		void attack();

	private:
		std::string name;
		Weapon* weapon; //Use Pointer: weapon can be NULL or change
};

#endif
