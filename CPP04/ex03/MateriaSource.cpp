/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:42:41 by abillote          #+#    #+#             */
/*   Updated: 2025/07/23 17:55:26 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		database[i] = NULL;
};

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (database[i])
			database[i] = other.database[i]->clone();
		else
			database[i] = NULL;
	}
};

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete database[i];
			if (other.database[i])
				database[i] = other.database[i]->clone();
			else
				database[i] = NULL;
		}
	}
	return *this;
};

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete database[i];
};

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (database[i] == NULL)
		{
			database[i] = m;
			return;
		}
	}
	std::cout << "Database is full!\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (database[i] && database[i]->getType() == type)
			return database[i]->clone();
	}
	return NULL;
}
