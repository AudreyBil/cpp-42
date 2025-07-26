/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:03 by abillote          #+#    #+#             */
/*   Updated: 2025/07/25 11:03:37 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
	std::cout << CYAN << BOLD << "\n===Tests from the subject===" << RESET << "\n\n";
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << "The first animal is a " << i->getType() << " " << std::endl;
	std::cout << "The second animal is a " << j->getType() << " " << std::endl;
	std::cout << "The first animal says ";
	i->makeSound();
	std::cout << "The second animal says ";
	j->makeSound();
	std::cout << "The base class Animal says ";
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	}

	{
	std::cout << CYAN << BOLD << "\n===Testing Wrong Cat with Animal pointer - no virtual function===" << RESET << "\n\n";
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "The Wrong Cat is a " << wrongCat->getType() << " " << std::endl;
	std::cout << "The Wrong Cat says ";
	wrongCat->makeSound();
	std::cout << std::endl;
	delete wrongCat;
	}

	{
	std::cout << CYAN << BOLD << "\n===Testing Wrong Cat direct object - no virtual function===" << RESET << "\n\n";
	WrongCat wrongCat;
	std::cout << "The Wrong Cat is a " << wrongCat.getType() << " " << std::endl;
	std::cout << "The Wrong Cat says ";
	wrongCat.makeSound();
	std::cout << std::endl;
	}

	std::cout << CYAN << BOLD << "\n===Testing Copy Constructor and Assignment===" << RESET << "\n\n";
	Cat originalCat;
	std::cout << "Original cat type: " << originalCat.getType() << std::endl;
	originalCat.makeSound();

	std::cout << "\n--- Copy Constructor ---" << std::endl;
	Cat copiedCat(originalCat);
	std::cout << "Copied cat type: " << copiedCat.getType() << std::endl;
	copiedCat.makeSound();

	std::cout << "\n--- Assignment Operator ---" << std::endl;
	Cat assignedCat;
	assignedCat = originalCat;
	std::cout << "Assigned cat type: " << assignedCat.getType() << std::endl;
	assignedCat.makeSound();

	std::cout << CYAN << BOLD << "\n===Testing Custom Type Constructor===" << RESET << "\n\n";
	std::cout << "Note: Cat and Dog types are always fixed, regardless of constructor parameter" << std::endl;
	Cat customCat("Siamese");  // This parameter will be ignored
	Dog customDog("Golden Retriever");  // This parameter will be ignored
	std::cout << "Custom cat type: " << customCat.getType() << " (should always be 'Cat')" << std::endl;
	std::cout << "Custom dog type: " << customDog.getType() << " (should always be 'Dog')" << std::endl;
	customCat.makeSound();
	customDog.makeSound();

	std::cout << CYAN << BOLD << "\n===Testing Array of Animals (Polymorphism)===" << RESET << "\n\n";
	Animal* animals[4];
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog("ignored_parameter");

	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " type: " << animals[i]->getType() << " - ";
		animals[i]->makeSound();
	}

	std::cout << "\n--- Cleaning up array ---" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	return 0;
}
