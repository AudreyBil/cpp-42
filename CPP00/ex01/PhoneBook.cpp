/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:27 by abillote          #+#    #+#             */
/*   Updated: 2025/07/15 14:24:19 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
: m_contactCount(0), m_nextContactNumber(1)
{

};

PhoneBook::~PhoneBook()
{

};

Contact PhoneBook::getOldestContact() const
{
	int oldestIndex = 0;

	for (int i = 1; i < m_contactCount; i++)
	{
		if (contact[i].getContactNumber() < contact[oldestIndex].getContactNumber())
		{
			oldestIndex = i;
		}
	}
	return (contact[oldestIndex]);
}

void PhoneBook::addContact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
	const std::string& phoneNumber, const std::string& darkestSecret)
{
	int index;
	int contactNumber = m_nextContactNumber++;

	 if (m_contactCount < MAX_CONTACTS) {
		index = m_contactCount;
		 m_contactCount++;
	} else {
		Contact oldestContact = getOldestContact();
		index = oldestContact.getIndex();
	}
	contact[index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret, contactNumber, index);

	std::cout << "Contact added successfully! Contact number: " << contactNumber << " and contact index: " << index << std::endl;
	std::cout << "Total contacts: " << m_contactCount << std::endl;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::right << std::setw(10) << "Index" << "|"
			  << std::right << std::setw(10) << "First Name" << "|"
			  << std::right << std::setw(10) << "Last Name" << "|"
			  << std::right << std::setw(10) << "Nickname" << std::endl;

	std::cout << std::string(43, '-') << std::endl;

	for (int i = 0; i < m_contactCount; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|"
				  << std::right << std::setw(10) << formatColumn(contact[i].getFirstName()) << "|"
				  << std::right << std::setw(10) << formatColumn(contact[i].getLastName()) << "|"
				  << std::right << std::setw(10) << formatColumn(contact[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContactDetails(int index) const
{
	std::cout << "First Name: " << contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contact[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getSelectedContactIndex() const
{
	std::string input;
	int index;
	bool validInput = false;

	do
	{
		std::cout << "Enter the index of the contact to display: ";
		std::getline(std::cin, input);
		if (input.empty() || isOnlyWhitespace(input)) {
			std::cout << "Index cannot be empty or contain only whitespace. Please try again.\n";
			continue;
		}
		if (!isValidNumber(input)) {
			std::cout << "Please enter a valid number.\n";
			continue;
		}

		index = atoi(input.c_str());
		if (index >= 0 && index < m_contactCount) {
			validInput = true;
		} else {
			std::cout << "Index must be between 0 and " << m_contactCount - 1 << ". Please try again.\n";
		}
	} while (!validInput);

	return (index);
}

void PhoneBook::searchContact()
{

	if (m_contactCount == 0)
	{
		std::cout << "Phonebook is empty\n";
		return ;
	}
	displayContacts();
	int index = getSelectedContactIndex();
	displayContactDetails(index);
}

