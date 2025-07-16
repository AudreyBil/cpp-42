/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:38:37 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 15:49:59 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "\n=== Creating a horde of Zombies ===\n";

	Zombie *horde = zombieHorde(10, "Ellie");
	for (int i = 0; i < 10; i++)
	{
		horde[i].announce();
	}

	delete [] horde;
}
