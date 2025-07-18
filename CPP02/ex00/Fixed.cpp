/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:40:11 by abillote          #+#    #+#             */
/*   Updated: 2025/07/18 14:24:21 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : m_fp_value(0) {
	std::cout << "Default constructor called\n";
};

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	this->m_fp_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignement operator called\n";
	if (this != &other) {
		this->m_fp_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return m_fp_value;
}

void Fixed::setRawBits(int const raw)
{
	m_fp_value = raw;
}
