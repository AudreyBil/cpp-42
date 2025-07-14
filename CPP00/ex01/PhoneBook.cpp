/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:27 by abillote          #+#    #+#             */
/*   Updated: 2025/07/14 14:50:52 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
: m_nbContacts(0)
{

};

PhoneBook::~PhoneBook()
{

};

//Give an incremental index to the contact to find out the oldest one
void PhoneBook::addContact(std::string first_name, std::string last_name, std::string nick_name,
	std::string phone_number, std::string darkest_secret)
{
	if (m_nbContacts == 8)
		contact[oldest_contact] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
	else

}



