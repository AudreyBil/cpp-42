/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:49:44 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 17:40:44 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class Weapon;

class HumanA
{
	public:
		HumanA(Weapon& Weapon);
		HumanA(std::string initialName, Weapon& Weapon);
		void attack();

	private:
		std::string name;
		Weapon& weapon; // Reference: weapon must exist and never change
};

#endif
