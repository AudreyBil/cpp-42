/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:49 by abillote          #+#    #+#             */
/*   Updated: 2025/07/15 14:14:28 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define MAX_CONTACTS 2

class PhoneBook
{
	public:
		//Constructors
		PhoneBook();
		~PhoneBook();

		//Member Functions
		void addContact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
						const std::string& phoneNumber, const std::string& darkestSecret);
		void displayContacts() const;
		void displayContactDetails(int index) const;
		void searchContact();
		int getSelectedContactIndex() const;

	private:
		int	m_contactCount;
		int m_nextContactNumber;
		Contact contact[MAX_CONTACTS];
		Contact getOldestContact() const;
};

bool isOnlyWhitespace(const std::string& str);
std::string formatColumn(const std::string& text);
bool isValidNumber(const std::string& str);

#endif
