/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:30:26 by abillote          #+#    #+#             */
/*   Updated: 2025/07/23 18:07:39 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void test_basic_functionality()
{
	std::cout << "=== Test 1: Subject Tests ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;
}

void test_inventory_limits()
{
	std::cout << "=== Test 2: Inventory Limits (4 slots max) ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* hero = new Character("hero");

	// Try to add 5 items (should only fit 4)
	for (int i = 0; i < 5; i++)
	{
		AMateria* tmp = src->createMateria("ice");
		if (tmp)
		{
			std::cout << "Equipping slot " << i << ". ";
			if (i < 4)
			{
				hero->equip(tmp);
			}
			else
			{
				hero->equip(tmp);
				delete tmp;
			}
		}
	}

	delete hero;
	delete src;
	std::cout << std::endl;
}

void test_unequip_functionality()
{
	std::cout << "=== Test 3: Unequip Functionality ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* witch = new Character("witch");
	ICharacter* target = new Character("target");

	// Equip and use
	AMateria* ice1 = src->createMateria("ice");
	witch->equip(ice1);
	std::cout << "Before unequip: ";
	witch->use(0, *target);

	// Unequip (materias left on floor - memory leak prevention responsibility)
	std::cout << "Unequipping slot 0..." << std::endl;
	witch->unequip(0);

	// Try to use unequipped slot (should do nothing)
	std::cout << "After unequip, trying to use: ";
	witch->use(0, *target);
	std::cout << "(Should do nothing)" << std::endl;

	// Clean up the unequipped materia manually
	delete ice1;
	delete target;
	delete witch;
	delete src;
	std::cout << std::endl;
}

void test_invalid_operations()
{
	std::cout << "=== Test 4: Invalid Operations ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* test_char = new Character("test");

	// Test invalid slot indices
	std::cout << "Testing invalid slot indices for use and unequip: (Should do nothing)" << std::endl;
	test_char->use(-1, *test_char);  // Invalid negative index
	test_char->use(4, *test_char);   // Invalid too high index

	test_char->unequip(-1);		  // Invalid negative index
	test_char->unequip(4);		   // Invalid too high index

	// Test equipping NULL
	std::cout << "Testing NULL equip: (Should do nothing)" << std::endl;
	test_char->equip(NULL);

	// Test creating unknown materia type
	std::cout << "Testing unknown materia type:" << std::endl;
	AMateria* unknown = src->createMateria("fireball");
	if (!unknown)
		std::cout << "Cannot create unknown materia type 'fireball'" << std::endl;

	delete test_char;
	delete src;
	std::cout << std::endl;
}

void test_materia_source_limits()
{
	std::cout << "=== Test 5: MateriaSource Limits (4 types max) ===" << std::endl;

	MateriaSource* src = new MateriaSource();

	// Learn more than 4 materias
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Learning materia " << i << ". ";

		AMateria* materia;
		if (i % 2 == 0)
			materia = new Ice();
		else
			materia = new Cure();

		if (i < 4)
		{
			// First 4 should be accepted
			src->learnMateria(materia);
		}
		else
		{
			// Last 2 should be rejected, so we need to clean them up
			src->learnMateria(materia);
			delete materia;  // Clean up the rejected materia
		}
	}

	delete src;
	std::cout << std::endl;
}

void test_deep_copy()
{
	std::cout << "=== Test 6: Deep Copy and Clone ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	// Test character copy
	Character* original = new Character("original");
	AMateria* ice = src->createMateria("ice");
	original->equip(ice);

	Character* copy = new Character(*original);  // Copy constructor
	ICharacter* target = new Character("target");

	std::cout << "Original character uses materia: ";
	original->use(0, *target);

	std::cout << "Copied character uses materia: ";
	copy->use(0, *target);

	std::cout << "Original name: " << original->getName() << std::endl;
	std::cout << "Copy name: " << copy->getName() << std::endl;

	delete target;
	delete copy;
	delete original;
	delete src;
	std::cout << std::endl;
}

void test_materia_types()
{
	std::cout << "=== Test 7: Materia Type Checking ===" << std::endl;

	Ice* ice = new Ice();
	Cure* cure = new Cure();

	std::cout << "Ice type: " << ice->getType() << std::endl;
	std::cout << "Cure type: " << cure->getType() << std::endl;

	// Test cloning preserves type
	AMateria* ice_clone = ice->clone();
	AMateria* cure_clone = cure->clone();

	std::cout << "Ice clone type: " << ice_clone->getType() << std::endl;
	std::cout << "Cure clone type: " << cure_clone->getType() << std::endl;

	delete ice;
	delete cure;
	delete ice_clone;
	delete cure_clone;
	std::cout << std::endl;
}

int main()
{
	test_basic_functionality();
	test_inventory_limits();
	test_unequip_functionality();
	test_invalid_operations();
	test_materia_source_limits();
	test_deep_copy();
	test_materia_types();

	return 0;
}
