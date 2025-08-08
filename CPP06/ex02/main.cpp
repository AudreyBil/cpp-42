/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:15:45 by abillote          #+#    #+#             */
/*   Updated: 2025/08/08 10:43:08 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base* generate(void)
{
	int defineClass = rand() % 3;
	Base *ptr;

	switch(defineClass)
	{
		case 0:
		{
			ptr = new A;
			break;
		}
		case 1:
		{
			ptr = new B;
			break;
		}
		case 2:
		{
			ptr = new C;
			break;
		}
		default:
			break;
	};
	return (ptr);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object pointed by p is of type A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Object pointed by p is of type B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Object pointed by p is of type C\n";
	else
		std::cout <<"Object is not of type A, B nor C\n";
}

void identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "Object referenced by p is of type A\n";
		return;
	} catch (const std::exception &e) { }

	try {
		dynamic_cast<B&>(p);
		std::cout << "Object referenced by p is of type B\n";
		return;
	} catch (const std::exception &e) { }

	try {
		dynamic_cast<C&>(p);
		std::cout << "Object referenced by p is of type C\n";
		return;
	} catch (const std::exception &e) { }

	std::cout << "Object is not of type A, B nor C\n";

}

int main()
{
	srand(time(0));
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}
