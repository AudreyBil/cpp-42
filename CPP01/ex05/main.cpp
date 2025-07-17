/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:47:39 by abillote          #+#    #+#             */
/*   Updated: 2025/07/17 11:24:28 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl harl;

	std::cout << "===Testing DEBUG level===\n";
	harl.complain("DEBUG");

	std::cout << "\n===Testing INFO level===\n";
	harl.complain("INFO");

	std::cout << "\n===Testing WARNING level===\n";
	harl.complain("WARNING");

	std::cout << "\n===Testing ERROR level===\n";
	harl.complain("ERROR");

	std::cout << "\n===Testing invalid level===\n";
	harl.complain("INVALID");
}
