/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:47:39 by abillote          #+#    #+#             */
/*   Updated: 2025/07/17 11:31:51 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error. You need to pass 1 and only 1 argument\n";
		return 1;
	}

	Harl harl;

	harl.complain(argv[1]);
}
