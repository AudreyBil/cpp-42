/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:28:02 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 12:14:24 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	//ClapTrap knight("Edwin");
	//ClapTrap drawer("Ewilan");
	//ScavTrap general("Hander");

	//std::cout << CYAN << "\n===Testing Attacks & Take Damage functions===" << RESET << "\n";
	//knight.setAttackDamage(3);
	//std::cout << BLUE << "ClapTrap Edwin prepares for battle (attack damage set to 3)" << RESET << "\n";
	//knight.attack("Hander");
	//general.takeDamage(3);
	//std::cout << BLUE << "\nScavTrap Hander hits back (attack damage set to default)" << RESET << "\n";
	//general.attack("Edwin");
	//knight.takeDamage(20);

	//std::cout << CYAN << "\n===Testing Repair functions==="<< RESET << "\n";
	//std::cout << BLUE << "ClapTrap Edwin attempts to heal..." << RESET << "\n";
	//knight.beRepaired(15);
	//std::cout << BLUE << "\nScavTrap Hander attempts to heal..." << RESET << "\n";
	//general.beRepaired(15);

	//std::cout << CYAN << "\n===Testing Gate keeper mode==="<< RESET << "\n";
	//general.guardGate();

	//std::cout << CYAN << "\n===Testing Copy Constructor & Assignment ==="<< RESET << "\n";
	//ScavTrap copyGeneral(general);
	//copyGeneral.attack("Ewilan");
	//drawer.takeDamage(20);

	//std::cout << std::endl;

	std::cout << CYAN << "\n===Creating a Claptrap with default constructor===" << RESET << "\n";
	ClapTrap defaultBase;
	std::cout << CYAN << "\n===Creating a Scavtrap with default constructor===" << RESET << "\n";
	ScavTrap defaultDerived;

	std::cout << CYAN << "\n===Creating a Claptrap with default constructor taking a name parameter===" << RESET << "\n";
	ClapTrap base2("Base");
	std::cout << CYAN << "\n===Creating a Scavtrap with default constructor taking a name parameter===" << RESET << "\n";
	ScavTrap derived2("Derived");

	std::cout << CYAN << "\n===ClapTrap attack()===" << RESET << "\n";
	base2.attack("Another ClapTrap");
	std::cout << CYAN << "\n===ScavTrap attack() - should override ClapTrap attack()===" << RESET << "\n";
	derived2.attack("Another ScavTrap");

	std::cout << CYAN << "\n===ClapTrap beRepaired()===" << RESET << "\n";
	base2.beRepaired(4);
	std::cout << CYAN << "\n===ScavTrap beRepaired() - should call ClapTrap beRepaired()===" << RESET << "\n";
	derived2.beRepaired(4);

	std::cout << CYAN << "\n===Comparing default stats===" << RESET << "\n";
	ClapTrap clap("StatTest");
	ScavTrap scav("StatTest");

	std::cout << YELLOW << "ClapTrap - HP: " << clap.getHitPoints()
			<< ", Energy: " << clap.getEnergyPoints()
			<< ", Attack: " << clap.getAttackDamage() << std::endl;
	std::cout << MAGENTA << "ScavTrap - HP: " << scav.getHitPoints()
			<< ", Energy: " << scav.getEnergyPoints()
			<< ", Attack: " << scav.getAttackDamage() << std::endl;

	std::cout << CYAN << "\n===Testing Gate keeper mode==="<< RESET << "\n";
	derived2.guardGate();

	std::cout << CYAN << "\n===ClapTrap Copy constructors===" << RESET << "\n";
	ClapTrap baseCopy(base2);
	std::cout << MAGENTA << "Original Claptrap energy points = " << base2.getEnergyPoints()  << RESET << "\n";
	std::cout << YELLOW << "Copy Claptrap energy points = " << baseCopy.getEnergyPoints()  << RESET << "\n";

	std::cout << CYAN << "\n===ScavTrap Copy constructors===" << RESET << "\n";
	ScavTrap derivedCopy(derived2);
	std::cout << MAGENTA << "Original Scavtrap energy points = " << derived2.getEnergyPoints()  << RESET << "\n";
	std::cout << YELLOW << "Copy Scavtrap energy points = " << derivedCopy.getEnergyPoints()  << RESET << "\n";

	std::cout << CYAN << "\n===ClapTrap assignment operators===" << RESET << "\n";
	ClapTrap assignTest1("AssignTest");
	assignTest1 = base2;
	std::cout << MAGENTA << "Original Claptrap name = " << base2.getName()  << RESET << "\n";
	std::cout << YELLOW << "AssignTest name = " << assignTest1.getName()  << RESET << "\n";

	std::cout << CYAN << "\n===ScavTrap assignment operators===" << RESET << "\n";
	ScavTrap assignTest2("AssignTest");
	assignTest2 = derived2;
	std::cout << MAGENTA << "Original Scavtrap name = " << derived2.getName()  << RESET << "\n";
	std::cout << YELLOW << "AssignTest name = " << assignTest2.getName()  << RESET << "\n";

	std::cout << CYAN << "\n===Creating a ClapTrap pointer to a ScavTrap object===" << RESET << "\n";
	ClapTrap *instance = new ScavTrap;
	std::cout << CYAN << "\n===ScavTrap instance calling attack() - Should call ScavTrap attack()===" << RESET << "\n";
	instance->attack("someone");
	delete instance;

	std::cout << CYAN << "\n===Re-initializing ClapTrap pointer to a ClapTrap object===" << RESET << "\n";
	instance = new ClapTrap;
	std::cout << CYAN << "\n===ClapTrap instance calling attack() - Should call ClapTrap attack()===" << RESET << "\n";
	instance->attack("someone");
	delete instance;

	std::cout << CYAN << "\n===Testing death scenarios===" << RESET << "\n";
	ScavTrap deathTest("DeathTest");
	deathTest.takeDamage(150);
	deathTest.attack("Someone");
	deathTest.beRepaired(10);
	deathTest.guardGate();

	std::cout << std::endl;

}
