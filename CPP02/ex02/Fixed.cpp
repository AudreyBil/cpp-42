/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:40:11 by abillote          #+#    #+#             */
/*   Updated: 2025/07/18 18:29:18 by abillote         ###   ########.fr       */
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

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called\n";
	m_fp_value = input << m_fractionalBits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called\n";
	m_fp_value = (int)roundf(input * (1 << m_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (float)m_fp_value / (1 << m_fractionalBits);
}

int Fixed::toInt(void) const
{
	return (int)m_fp_value >> m_fractionalBits;
}


int Fixed::getRawBits(void) const
{
	return m_fp_value;
}

void Fixed::setRawBits(int const raw)
{
	m_fp_value = raw;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->m_fp_value > other.m_fp_value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->m_fp_value < other.m_fp_value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->m_fp_value >= other.m_fp_value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->m_fp_value <= other.m_fp_value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->m_fp_value == other.m_fp_value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->m_fp_value != other.m_fp_value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.m_fp_value = this->m_fp_value + other.m_fp_value;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.m_fp_value = this->m_fp_value - other.m_fp_value;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	long long temp = (long long)this->m_fp_value * other.m_fp_value;
	result.m_fp_value = (int)(temp >> m_fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	long long temp = (long long)this->m_fp_value << m_fractionalBits / other.m_fp_value;
	result.m_fp_value = (int)(temp);
	return result;
}

Fixed& Fixed::operator++()
{
	++this->m_fp_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old_value(*this);
	++this->m_fp_value;
	return old_value;
}

Fixed& Fixed::operator--()
{
	--this->m_fp_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old_value(*this);
	--this->m_fp_value;
	return old_value;
}

Fixed& Fixed::min(Fixed& fp1, Fixed& fp2)
{
	if (fp1.m_fp_value < fp2.m_fp_value)
		return (fp1);
	else
		return (fp2);
}

const Fixed& Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
	if (fp1.m_fp_value < fp2.m_fp_value)
		return (fp1);
	else
		return (fp2);
}
Fixed& Fixed::max(Fixed& fp1, Fixed& fp2)
{
	if (fp1.m_fp_value > fp2.m_fp_value)
		return (fp1);
	else
		return (fp2);
}

const Fixed& Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
	if (fp1.m_fp_value > fp2.m_fp_value)
		return (fp1);
	else
		return (fp2);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
