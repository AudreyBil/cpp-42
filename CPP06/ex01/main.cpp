/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:15:45 by abillote          #+#    #+#             */
/*   Updated: 2025/08/07 10:51:19 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data* ptr = new Data;
	ptr->age = 32;
	ptr->name = "Marge";
	ptr->nbChildren = 3;

	std::cout << "Original Pointer: " << ptr << std::endl;
	std::cout << "Value in original pointer: age = " << ptr->age << ", name = "
	<< ptr->name << ", number of children = " << ptr->nbChildren << std::endl;
	uintptr_t addr = Serializer::serialize(ptr);

	std::cout << "\nPointer address as integer (after Serialize function): " << addr << std::endl;

	Data* restoredPtr = Serializer::deserialize(addr);
	std::cout << "\nRestored pointer (should be same as original): " << restoredPtr << std::endl;
	std::cout << "Value through restored pointer: age = " << restoredPtr->age << ", name = "
	<< restoredPtr->name << ", number of children = " << restoredPtr->nbChildren << std::endl;
	delete ptr;
}
