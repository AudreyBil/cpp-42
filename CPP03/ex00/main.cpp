/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:28:02 by abillote          #+#    #+#             */
/*   Updated: 2025/07/20 13:42:10 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap knight("Edwin");
	ClapTrap spy("Ellana");
	ClapTrap wolf("Salim");
	ClapTrap drawer("Ewilan");

	std::cout << CYAN << "\n===Testing Attacks & Take Damage functions===" << RESET << "\n";
	knight.setAttackDamage(3);
	std::cout << BLUE << "Edwin prepares for battle (attack damage set to 3)" << RESET << "\n";
	knight.attack("Ewilan");
	drawer.takeDamage(3);

	std::cout << CYAN << "\n===Testing Repair functions==="<< RESET << "\n";
	std::cout << BLUE << "Ewilan attempts to heal..." << RESET << "\n";
	drawer.beRepaired(1);

	std::cout << CYAN << "\n===Testing no energy points left===" << RESET << "\n";
	std::cout << BOLD << RED << "\n***Edwin goes on a rampage!***" << RESET << "\n";
	std::cout << MAGENTA << "\n--- Edwin vs Ewilan ---" << RESET << "\n";
	knight.attack("Ewilan");
	drawer.takeDamage(3);
	knight.attack("Ewilan");
	drawer.takeDamage(3);
	knight.attack("Ewilan");
	drawer.takeDamage(3);

	std::cout << MAGENTA << "\n--- Edwin turns towards Salim ---" << RESET << "\n";
	knight.attack("Salim");
	wolf.takeDamage(3);
	knight.attack("Salim");
	wolf.takeDamage(3);
	knight.attack("Salim");
	wolf.takeDamage(3);
	knight.attack("Salim");
	wolf.takeDamage(3);

	std::cout << MAGENTA << "\n--- Edwin's final assault on Ellana ---" << RESET << "\n";
	knight.attack("Ellana");
	spy.takeDamage(3);
	knight.attack("Ellana");
	spy.takeDamage(3);
	knight.attack("Ellana");

	std::cout << CYAN << "\n===[ DEATH & REVIVAL TESTING ]===" << RESET << "\n";
	std::cout << BLUE << "Ellana's revenge attempt..." << RESET << "\n";
	spy.setAttackDamage(1);
	spy.attack("Ewilan");
	drawer.takeDamage(1);
	std::cout << BLUE << "Attempting to revive Ewilan..." << RESET << "\n";
	drawer.beRepaired(10);

	std::cout << CYAN << "\n===[ REPAIR LIMIT TESTING ]===" << RESET << "\n";
	std::cout << BLUE << "Ellana tries to over-heal..." << RESET << "\n";
	spy.beRepaired(15);
	spy.beRepaired(1);
	std::cout << std::endl;
}
