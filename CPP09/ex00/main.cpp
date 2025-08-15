/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:13:16 by abillote          #+#    #+#             */
/*   Updated: 2025/08/14 12:03:17 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "Error: could not open file\n";
		return 1;
	}
	if (argc > 2) {
		std::cout << "Error: You must pass only one file\n";
		return 1;
	}

	try {
		class BitcoinExchange btc("data.csv");
		btc.processInputFile(argv[1]);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what();
		return 1;
	}
	return 0;
}
