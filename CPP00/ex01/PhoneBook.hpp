/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:42:49 by abillote          #+#    #+#             */
/*   Updated: 2025/07/14 14:46:51 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <array>
#include <string>
#include "Contact.hpp"


class PhoneBook
{
	public:
		//Constructors
		PhoneBook();
		~PhoneBook();

		//Members
		Contact contact[8];

		void addContact(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret);

	private:
		int	m_nbContacts;
};

#endif
