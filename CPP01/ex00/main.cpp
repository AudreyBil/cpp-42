/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:38:37 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 14:51:56 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "\n=== Testing newZombie function (heap allocation) ===\n";

	Zombie *z1 = newZombie("Joel");
	Zombie *z2 = newZombie("Ellie");

	z1->announce();
	z2->announce();

	delete z1;
	delete z2;

	std::cout << "\n=== Testing randomChump function (stack allocation) ===\n";

	randomChump("Tommy");
	randomChump("Abby");
	randomChump("Dina");
}
