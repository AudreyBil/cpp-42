/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:16:58 by abillote          #+#    #+#             */
/*   Updated: 2025/07/23 16:38:43 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

};

Cure::Cure(const Cure& other) : AMateria(other)
{

};

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{

};

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
