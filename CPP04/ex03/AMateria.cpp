/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:04:42 by abillote          #+#    #+#             */
/*   Updated: 2025/07/23 15:19:56 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{

};
AMateria::AMateria(std::string const & type)
: m_type(type)
{

};

AMateria::AMateria(const AMateria& other)
{
	this->m_type = other.m_type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->m_type = other.m_type;
	return *this;
}

AMateria::~AMateria()
{

};

std::string const & AMateria::getType() const
{
	return m_type;
}
