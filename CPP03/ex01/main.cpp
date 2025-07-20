/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:28:02 by abillote          #+#    #+#             */
/*   Updated: 2025/07/20 14:57:44 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap knight("Edwin");
	ClapTrap drawer("Ewilan");
	ScavTrap general("Hander");

	std::cout << CYAN << "\n===Testing Attacks & Take Damage functions===" << RESET << "\n";
	knight.setAttackDamage(3);
	std::cout << BLUE << "ClapTrap Edwin prepares for battle (attack damage set to 3)" << RESET << "\n";
	knight.attack("Hander");
	general.takeDamage(3);
	std::cout << BLUE << "\nScavTrap Hander hits back (attack damage set to default)" << RESET << "\n";
	general.attack("Edwin");
	knight.takeDamage(20);

	std::cout << CYAN << "\n===Testing Repair functions==="<< RESET << "\n";
	std::cout << BLUE << "ClapTrap Edwin attempts to heal..." << RESET << "\n";
	knight.beRepaired(15);
	std::cout << BLUE << "\nScavTrap Hander attempts to heal..." << RESET << "\n";
	general.beRepaired(15);

	std::cout << CYAN << "\n===Testing Gate keeper mode==="<< RESET << "\n";
	general.guardGate();

	std::cout << CYAN << "\n===Testing Copy Constructor & Assignment ==="<< RESET << "\n";
	ScavTrap copyGeneral(general);
	copyGeneral.attack("Ewilan");
	drawer.takeDamage(20);

	std::cout << std::endl;
}
