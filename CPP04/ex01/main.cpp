/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:03 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 21:44:46 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << CYAN << BOLD << "\n===Testing Array of Animals (Polymorphism)===" << RESET << "\n\n";
	Animal* animals[4];
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();

	for (int i = 0;i < 4; i++)
	{
		if (animals[i]->getType() == "Cat")
			static_cast<Cat*>(animals[i])->getBrain()->setIdea(0, "I am a cat with a brain");
		else
			static_cast<Dog*>(animals[i])->getBrain()->setIdea(0, "I am a dog with a brain");
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " type: " << animals[i]->getType() << " - ";
		animals[i]->makeSound();
		if (animals[i]->getType() == "Cat")
			static_cast<Cat*>(animals[i])->getBrain()->printIdeas(1);
		else
			static_cast<Dog*>(animals[i])->getBrain()->printIdeas(1);
	}

	std::cout << "\n--- Cleaning up array ---" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	std::cout << CYAN << BOLD << "\n===Testing Brain Deep Copying with Copy Constructor===" << RESET << "\n\n";
	Cat cat;
	cat.getBrain()->setIdea(0, "I need to eat.");
	cat.getBrain()->setIdea(1, "Let's find a human.");
	cat.getBrain()->setIdea(2, "Oh, here is one, let's mew.");
	cat.getBrain()->setIdea(3, "Here we go, give me food human.");

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
	copyCat.getBrain()->setIdea(2, "Oh look, a fish tank!");
	copyCat.getBrain()->setIdea(3, "Let's get in there");

	std::cout << GREEN << "Original Cat Ideas:" << RESET << "\n";
	cat.getBrain()->printIdeas();
	std::cout << GREEN << "Copied Cat Ideas:" << RESET << "\n";
	copyCat.getBrain()->printIdeas();

	std::cout << CYAN << BOLD << "\n===Testing Brain Deep Copying with Copy assignment operator===" << RESET << "\n\n";
	Dog dog;
	dog.getBrain()->setIdea(0, "I need to eat.");
	dog.getBrain()->setIdea(1, "Let's find a human.");
	dog.getBrain()->setIdea(2, "Oh, here is one, let's bark.");
	dog.getBrain()->setIdea(3, "Here we go, give me food human.");

	Dog copyDog;
	copyDog = dog;

	std::cout << CYAN << "Original Dog brain address: " << dog.getBrain() << RESET << std::endl;
	std::cout << CYAN << "Copied Dog brain address: " << copyDog.getBrain() << RESET << std::endl;
	std::cout << CYAN << "Different brain addresses ? (answer should be 1): "
				<< (copyDog.getBrain() != dog.getBrain()) << RESET << "\n";

	std::cout << GREEN << "Original Dog Ideas:" << RESET << "\n";
	dog.getBrain()->printIdeas();
	std::cout << GREEN << "Copied Dog Ideas:" << RESET << "\n";
	copyDog.getBrain()->printIdeas();

	std::cout << CYAN << "Modifying the Copied Dog Brain ideas "<< RESET << "\n";
	copyDog.getBrain()->setIdea(0, "I love running and jumping.");
	copyDog.getBrain()->setIdea(1, "Where could I jump?");
	copyDog.getBrain()->setIdea(2, "Oh look, a couch!");
	copyDog.getBrain()->setIdea(3, "Let's get up there");

	std::cout << GREEN << "Original Dog Ideas:" << RESET << "\n";
	dog.getBrain()->printIdeas();
	std::cout << GREEN << "Copied Dog Ideas:" << RESET << "\n";
	copyDog.getBrain()->printIdeas();

	std::cout << CYAN << BOLD << "\n===Testing Self Assignment===" << RESET << "\n\n";

	Cat cat2;
	cat2.getBrain()->setIdea(0, "Yes, still there");

	std::cout << "Before self-assignment - Brain address: " << cat2.getBrain() << std::endl;
	cat2 = cat2;  // Self assignment
	std::cout << "After self-assignment - Brain address: " << cat2.getBrain() << std::endl;
	std::cout << "Idea still there: " << cat2.getBrain()->getIdea(0) << std::endl << std::endl;

	return 0;
}
