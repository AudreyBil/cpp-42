/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:25:42 by abillote          #+#    #+#             */
/*   Updated: 2025/07/22 21:29:09 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const;
		Brain *getBrain() const;

	private:
		Brain* m_brain;
};


#endif
