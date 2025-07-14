/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:45 by abillote          #+#    #+#             */
/*   Updated: 2025/07/14 14:45:39 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>


void getUserInput(PhoneBook phonebook)
{
	std::string first_name;
	std::cout << "User First Name:";
	std::getline(std::cin, first_name);
	std::string last_name;
	std::cout << "User Last Name:";
	std::getline(std::cin, last_name);
	std::string nickname;
	std::cout << "User Nickname:";
	std::getline(std::cin, nickname);
	std::string phone_number;
	std::cout << "User Phone number:";
	std::getline(std::cin, phone_number);
	std::string darkest_secret;
	std::cout << "User Darkest Secret:";
	std::getline(std::cin, darkest_secret);
	phonebook.addContact(first_name, last_name, nickname, phone_number, darkest_secret);
}

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT\n";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			getUserInput(phonebook);
		}
		else if (command == "SEARCH")
		{
			searchContact(phonebook);
		}
		else if (command == "EXIT")
		{
			PhoneBook::~PhoneBook(phonebook);
			return 0;
		}
	}

}
