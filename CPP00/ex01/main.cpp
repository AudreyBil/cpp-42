/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:45 by abillote          #+#    #+#             */
/*   Updated: 2025/07/17 13:06:06 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool isValidNumber(const std::string& str) {
	if (str.empty()) return false;

	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

std::string formatColumn(const std::string& text)
{
	if (text.length() <= 10)
		return text;
	else
	 return text.substr(0,9) + ".";
}

bool isOnlyWhitespace(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

std::string getValidatedInput(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty() || isOnlyWhitespace(input))
			std::cout << "Input cannot be empty or contain only whitespace. Please try again.\n";
	} while (input.empty() || isOnlyWhitespace(input));
	return input;
}

void getUserInput(PhoneBook& phonebook)
{
	std::string firstName = getValidatedInput("User First Name: ");
	std::string lastName = getValidatedInput("User Last Name: ");
	std::string nickname = getValidatedInput("User Nickname: ");
	std::string phoneNumber = getValidatedInput("User Phone number: ");
	std::string darkestSecret = getValidatedInput("User Darkest Secret: ");

	phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT\n";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
		{
			getUserInput(phonebook);
		}
		else if (command == "SEARCH")
		{
			phonebook.searchContact();
		}
		else if (command == "EXIT")
		{
			return 0;
		}
	}
}
