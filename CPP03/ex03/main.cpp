/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:28:02 by abillote          #+#    #+#             */
/*   Updated: 2025/07/20 20:24:38 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap knight("Edwin");
	ClapTrap drawer("Ewilan");
	FragTrap king("Sai");

	std::cout << CYAN << "\n===Testing Attacks & Take Damage functions===" << RESET << "\n";
	knight.setAttackDamage(3);
	std::cout << BLUE << "ClapTrap Edwin prepares for battle (attack damage set to 3)" << RESET << "\n";
	knight.attack("Sai");
	king.takeDamage(3);
	std::cout << BLUE << "\nFragTrap Sai hits back (attack damage set to default)" << RESET << "\n";
	king.attack("Edwin");

	std::cout << CYAN << "\n===Testing Repair functions==="<< RESET << "\n";
	std::cout << BLUE << "ClapTrap Edwin attempts to heal..." << RESET << "\n";
	knight.beRepaired(15);
	std::cout << BLUE << "\nFragTrap Hander attempts to heal..." << RESET << "\n";
	king.beRepaired(15);

	std::cout << CYAN << "\n===Testing High Five==="<< RESET << "\n";
	king.highFivesGuys();

	std::cout << CYAN << "\n===Testing Copy Constructor & Assignment ==="<< RESET << "\n";
	FragTrap copyKing(king);
	copyKing.attack("Ewilan");

	std::cout << std::endl;
}
