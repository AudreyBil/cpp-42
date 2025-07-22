/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:28:02 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 12:11:58 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	//ClapTrap knight("Edwin");
	//ClapTrap drawer("Ewilan");
	//FragTrap king("Sai");

	//std::cout << CYAN << "\n===Testing Attacks & Take Damage functions===" << RESET << "\n";
	//knight.setAttackDamage(3);
	//std::cout << BLUE << "ClapTrap Edwin prepares for battle (attack damage set to 3)" << RESET << "\n";
	//knight.attack("Sai");
	//king.takeDamage(3);
	//std::cout << BLUE << "\nFragTrap Sai hits back (attack damage set to default)" << RESET << "\n";
	//king.attack("Edwin");

	//std::cout << CYAN << "\n===Testing Repair functions==="<< RESET << "\n";
	//std::cout << BLUE << "ClapTrap Edwin attempts to heal..." << RESET << "\n";
	//knight.beRepaired(15);
	//std::cout << BLUE << "\nFragTrap Hander attempts to heal..." << RESET << "\n";
	//king.beRepaired(15);

	//std::cout << CYAN << "\n===Testing High Five==="<< RESET << "\n";
	//king.highFivesGuys();

	//std::cout << CYAN << "\n===Testing Copy Constructor & Assignment ==="<< RESET << "\n";
	//FragTrap copyKing(king);
	//copyKing.attack("Ewilan");

	//std::cout << std::endl;

	std::cout << CYAN << "\n===Creating a Claptrap with default constructor===" << RESET << "\n";
	ClapTrap defaultBase;
	std::cout << CYAN << "\n===Creating a Fragtrap with default constructor===" << RESET << "\n";
	FragTrap defaultDerived;

	std::cout << CYAN << "\n===Creating a Claptrap with default constructor taking a name parameter===" << RESET << "\n";
	ClapTrap base2("Base");
	std::cout << CYAN << "\n===Creating a Fragtrap with default constructor taking a name parameter===" << RESET << "\n";
	FragTrap derived2("Derived");

	std::cout << CYAN << "\n===ClapTrap attack()===" << RESET << "\n";
	base2.attack("Another ClapTrap");
	std::cout << CYAN << "\n===FragTrap attack() - should call ClapTrap attack()===" << RESET << "\n";
	derived2.attack("Another FragTrap");

	std::cout << CYAN << "\n===ClapTrap beRepaired()===" << RESET << "\n";
	base2.beRepaired(4);
	std::cout << CYAN << "\n===FragTrap beRepaired() - should call ClapTrap beRepaired()===" << RESET << "\n";
	derived2.beRepaired(4);

	std::cout << CYAN << "\n===Comparing default stats===" << RESET << "\n";
	ClapTrap clap("StatTest");
	FragTrap frag("StatTest");

	std::cout << YELLOW << "ClapTrap - HP: " << clap.getHitPoints()
			<< ", Energy: " << clap.getEnergyPoints()
			<< ", Attack: " << clap.getAttackDamage() << std::endl;
	std::cout << MAGENTA << "FragTrap - HP: " << frag.getHitPoints()
			<< ", Energy: " << frag.getEnergyPoints()
			<< ", Attack: " << frag.getAttackDamage() << std::endl;

	std::cout << CYAN << "\n===Testing High Five Function==="<< RESET << "\n";
	derived2.highFivesGuys();

	std::cout << CYAN << "\n===ClapTrap Copy constructors===" << RESET << "\n";
	ClapTrap baseCopy(base2);
	std::cout << MAGENTA << "Original Claptrap energy points = " << base2.getEnergyPoints()  << RESET << "\n";
	std::cout << YELLOW << "Copy Claptrap energy points = " << baseCopy.getEnergyPoints()  << RESET << "\n";

	std::cout << CYAN << "\n===FragTrap Copy constructors===" << RESET << "\n";
	FragTrap derivedCopy(derived2);
	std::cout << MAGENTA << "Original Fragtrap energy points = " << derived2.getEnergyPoints()  << RESET << "\n";
	std::cout << YELLOW << "Copy Fragtrap energy points = " << derivedCopy.getEnergyPoints()  << RESET << "\n";

	std::cout << CYAN << "\n===ClapTrap assignment operators===" << RESET << "\n";
	ClapTrap assignTest1("AssignTest");
	assignTest1 = base2;
	std::cout << MAGENTA << "Original Claptrap name = " << base2.getName()  << RESET << "\n";
	std::cout << YELLOW << "AssignTest name = " << assignTest1.getName()  << RESET << "\n";

	std::cout << CYAN << "\n===FragTrap assignment operators===" << RESET << "\n";
	FragTrap assignTest2("AssignTest");
	assignTest2 = derived2;
	std::cout << MAGENTA << "Original Fragtrap name = " << derived2.getName()  << RESET << "\n";
	std::cout << YELLOW << "AssignTest name = " << assignTest2.getName()  << RESET << "\n";

	std::cout << CYAN << "\n===Testing death scenarios===" << RESET << "\n";
	FragTrap deathTest("DeathTest");
	deathTest.takeDamage(150);
	deathTest.attack("Someone");
	deathTest.beRepaired(10);
	deathTest.highFivesGuys();

	std::cout << std::endl;
}
