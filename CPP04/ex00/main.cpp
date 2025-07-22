/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:03 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 14:21:32 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << CYAN << BOLD << "===Tests from the subject===" << RESET << "\n\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << CYAN << BOLD << "\n===Testing Wrong Cat - no virtual function===" << RESET << "\n\n";
	const WrongAnimal* base = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	base->makeSound();
	std::cout << std::endl;
	delete base;
	delete wrongCat;

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
