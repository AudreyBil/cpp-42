/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:37 by abillote          #+#    #+#             */
/*   Updated: 2025/07/15 14:25:56 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
: m_firstName(""), m_lastName(""), m_nickname(""),
m_phoneNumber(""), m_darkestSecret(""),
m_index(0), m_contactNumber(0)
{

};

Contact::~Contact()
{

};

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
	const std::string& phoneNumber, const std::string&darkestSecret, const int contactNumber, const int index)
: m_firstName(firstName), m_lastName(lastName), m_nickname(nickname), m_phoneNumber(phoneNumber),
m_darkestSecret(darkestSecret), m_index(index), m_contactNumber(contactNumber)
{

};

std::string Contact::getFirstName() const
{
	return (m_firstName);
}

std::string Contact::getLastName() const
{
	return (m_lastName);
}

std::string Contact::getNickname() const
{
	return (m_nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (m_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (m_darkestSecret);
}

int Contact::getIndex() const
{
	return (m_index);
}

int Contact::getContactNumber() const
{
	return (m_contactNumber);
}
