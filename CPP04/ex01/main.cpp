/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:03 by abillote          #+#    #+#             */
/*   Updated: 2025/07/25 11:18:57 by abillote         ###   ########.fr       */
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
	std::cout << CYAN << BOLD << "\n===Testing Array of Animals (Polymorphism)===" << RESET << "\n\n";
	Animal* animals[4];
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();

	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " type: " << animals[i]->getType() << " - ";
		animals[i]->makeSound();
	}

	std::cout << "\n--- Cleaning up array ---" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	}

	{
	std::cout << CYAN << BOLD << "\n===Basic test of deep Copying with Copy Constructor===" << RESET << "\n\n";
	Dog firstDog;
	{
		Dog tmp = firstDog;
	}
	firstDog.getBrain()->setIdea(0, "Original Brain is still alive!\n");
	firstDog.getBrain()->printIdeas();
	}

	{
	std::cout << CYAN << BOLD << "\n===More extensive test of Brain Deep Copying with Copy Constructor===" << RESET << "\n\n";
	Cat cat;
	cat.getBrain()->setIdea(0, "I need to eat.");
	cat.getBrain()->setIdea(1, "Let's find a human.");

	Cat copyCat(cat);

	std::cout << CYAN << "Original Cat brain address: " << cat.getBrain() << RESET << std::endl;
	std::cout << CYAN << "Copied Cat brain address: " << copyCat.getBrain() << RESET << std::endl;
	std::cout << CYAN << "Different brain addresses ? (answer should be 1): "
				<< (copyCat.getBrain() != cat.getBrain()) << RESET << "\n";

	std::cout << GREEN << "Original Cat Ideas:" << RESET << "\n";
	cat.getBrain()->printIdeas();
	std::cout << GREEN << "Copied Cat Ideas:" << RESET << "\n";
	copyCat.getBrain()->printIdeas();

	std::cout << CYAN << "Modifying the Copied Cat Brain ideas "<< RESET << "\n";
	copyCat.getBrain()->setIdea(0, "I love fish.");
	copyCat.getBrain()->setIdea(1, "Where could I find some?");

	std::cout << GREEN << "Original Cat Ideas:" << RESET << "\n";
	cat.getBrain()->printIdeas();
	std::cout << GREEN << "Copied Cat Ideas:" << RESET << "\n";
	copyCat.getBrain()->printIdeas();
	}

	{
	std::cout << CYAN << BOLD << "\n===Testing Brain Deep Copying with Copy Assignment operator Constructor===" << RESET << "\n\n";
	Dog dog;
	dog.getBrain()->setIdea(0, "I need to eat.");
	dog.getBrain()->setIdea(1, "Let's find a human.");

	Dog copyDog;
	copyDog = dog;

	std::cout << CYAN << "Original dog brain address: " << dog.getBrain() << RESET << std::endl;
	std::cout << CYAN << "Copied dog brain address: " << copyDog.getBrain() << RESET << std::endl;
	std::cout << CYAN << "Different brain addresses ? (answer should be 1): "
				<< (copyDog.getBrain() != dog.getBrain()) << RESET << "\n";

	std::cout << GREEN << "Original dog Ideas:" << RESET << "\n";
	dog.getBrain()->printIdeas(2);
	std::cout << GREEN << "Copied dog Ideas:" << RESET << "\n";
	copyDog.getBrain()->printIdeas(2);

	std::cout << CYAN << "Modifying the Copied Dog Brain ideas "<< RESET << "\n";
	copyDog.getBrain()->setIdea(0, "I love  running and jumping around.");
	copyDog.getBrain()->setIdea(1, "Where could I do that?");

	std::cout << GREEN << "Original Dog Ideas:" << RESET << "\n";
	dog.getBrain()->printIdeas(2);
	std::cout << GREEN << "Copied Dog Ideas:" << RESET << "\n";
	copyDog.getBrain()->printIdeas(2);
	}

	return 0;
}
