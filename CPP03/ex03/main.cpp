/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:28:02 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 12:17:15 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << CYAN << "===Creating a DiamondTrap with default constructor===" << RESET << "\n";
	DiamondTrap diamond;

	std::cout << CYAN << "\n===Creating a Diamondtrap with default constructor taking a name parameter===" << RESET << "\n";
	DiamondTrap diamond1("Diamond1");

	std::cout << CYAN << "\n===DiamondTrap attack() - should call ScavTrap attack()===" << RESET << "\n";
	diamond1.attack("Someone");

	std::cout << CYAN << "\n===DiamondTrap beRepaired() - should call ClapTrap beRepaired()===" << RESET << "\n";
	diamond1.beRepaired(4);

	std::cout << CYAN << "\n===DiamondTrap takeDamage() - should call ClapTrap takeDamage()===" << RESET << "\n";
	diamond1.takeDamage(40);

	std::cout << CYAN << "\n===Comparing default stats===" << RESET << "\n";
	ClapTrap clap("StatTest");
	FragTrap frag("StatTest");
	ScavTrap scav("StatTest");
	DiamondTrap diam("StatTest");

	std::cout << YELLOW << "ClapTrap - HP: " << clap.getHitPoints()
			<< ", Energy: " << clap.getEnergyPoints()
			<< ", Attack: " << clap.getAttackDamage() << std::endl;
	std::cout << YELLOW << "FragTrap - HP: " << frag.getHitPoints()
			<< ", Energy: " << frag.getEnergyPoints()
			<< ", Attack: " << frag.getAttackDamage() << std::endl;
	std::cout << YELLOW << "ScavTrap - HP: " << scav.getHitPoints()
			<< ", Energy: " << scav.getEnergyPoints()
			<< ", Attack: " << scav.getAttackDamage() << std::endl;
	std::cout << MAGENTA << "DiamTrap - HP: " << diam.getHitPoints()
			<< ", Energy: " << diam.getEnergyPoints()
			<< ", Attack: " << diam.getAttackDamage() << std::endl;

	std::cout << CYAN << "\n===Testing Guard Gate function from ScavTrap==="<< RESET << "\n";
	diamond1.guardGate();

	std::cout << CYAN << "\n===Testing High Five function from FragTrap==="<< RESET << "\n";
	diamond1.highFivesGuys();

	std::cout << CYAN << "\n===Testing Who am I function==="<< RESET << "\n";
	diamond1.whoAmI();

	std::cout << CYAN << "\n===DiamondTrap Copy constructors===" << RESET << "\n";
	DiamondTrap diamondCopy(diamond1);
	std::cout << MAGENTA << "Diamondtrap name = " << diamond1.getName() << " and hit points = "
				<< diamond1.getHitPoints()<< RESET << "\n";
	std::cout << YELLOW << "Diamondcopy name = " << diamondCopy.getName()  << " and hit points = "
				<< diamondCopy.getHitPoints()<< RESET << "\n";

	std::cout << CYAN << "\n===DiamondTrap assignment operators===" << RESET << "\n";
	DiamondTrap assignTest("AssignTest");
	assignTest = diamond1;
	std::cout << MAGENTA << "Original DiamondTrap ClapTrap name = " << diamond1.getName()  << RESET << "\n";
	std::cout << YELLOW << "AssignTest ClapTrap name = " << assignTest.getName()  << RESET << "\n";

	std::cout << CYAN << "\n===Testing death scenarios===" << RESET << "\n";
	DiamondTrap deathTest("DeathTest");
	deathTest.takeDamage(150);
	deathTest.attack("Someone");
	deathTest.beRepaired(10);
	deathTest.guardGate();

	std::cout << CYAN << "\n===Testing polymorphism - Should use ScavTrap attack===" << RESET << "\n";
	ClapTrap* poly = new DiamondTrap("PolyTest");
	poly->attack("Target");
	delete poly;

	std::cout << std::endl;
}
