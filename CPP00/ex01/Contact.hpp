/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:41 by abillote          #+#    #+#             */
/*   Updated: 2025/07/15 13:56:01 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <cctype>

class Contact
{
	public:
		Contact();
		Contact(const std::string firstName, const std::string lastName, const std::string nickname,
			const std::string phoneNumber, const std::string darkestSecret, const int contactNumber, const int index);
		~Contact();

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		int getIndex() const;
		int getContactNumber() const;

	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickname;
		std::string m_phoneNumber;
		std::string m_darkestSecret;
		int m_index;
		int m_contactNumber;

};

#endif
