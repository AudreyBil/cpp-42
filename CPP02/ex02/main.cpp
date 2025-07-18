/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:40:03 by abillote          #+#    #+#             */
/*   Updated: 2025/07/18 18:28:35 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

# include <iostream>

int main() {
	std::cout << "=== BASIC FIXED POINT TEST ===" << std::endl;

	// Test constructors
	std::cout << "\n1. Testing constructors:" << std::endl;
	Fixed a;					// Default
	Fixed b(10);				// Integer
	Fixed c(42.42f);			// Float
	Fixed d(b);				 // Copy

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	// Test assignment
	std::cout << "\n2. Testing assignment:" << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "a = " << a << std::endl;
	std::cout << "a as integer = " << a.toInt() << std::endl;

	// Test comparisons
	std::cout << "\n3. Testing comparisons:" << std::endl;
	std::cout << "b > a: " << (b > a) << std::endl;
	std::cout << "b >= a: " << (b >= a) << std::endl;
	std::cout << "b < a: " << (b < a) << std::endl;
	std::cout << "b <= a: " << (b <= a) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	// Test arithmetic
	std::cout << "\n4. Testing arithmetic:" << std::endl;
	std::cout << "b + c = " << (b + c) << std::endl;
	std::cout << "c - b = " << (c - b) << std::endl;
	std::cout << "b * 2 = " << (b * Fixed(2)) << std::endl;
	std::cout << "c / 2 = " << (c / Fixed(2)) << std::endl;

	// Test increment/decrement
	std::cout << "\n5. Testing increment/decrement:" << std::endl;
	Fixed x(5);
	std::cout << "x = " << x << std::endl;
	std::cout << "++x = " << (++x) << std::endl;
	std::cout << "--x = " << (--x) << std::endl;
	std::cout << "x++ = " << (x++) << std::endl;
	std::cout << "x-- = " << (x--) << std::endl;
	std::cout << "x = " << x << std::endl;

	// Test min/max
	std::cout << "\n6. Testing min/max:" << std::endl;
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;

	// Subject example
	std::cout << "\n7. Exercise example:" << std::endl;
	Fixed test_a;
	Fixed const test_b(Fixed(5.05f) * Fixed(2));

	std::cout << test_a << std::endl;
	std::cout << ++test_a << std::endl;
	std::cout << test_a << std::endl;
	std::cout << test_a++ << std::endl;
	std::cout << test_a << std::endl;
	std::cout << test_b << std::endl;
	std::cout << Fixed::max(test_a, test_b) << std::endl;

	std::cout << "\n=== TEST COMPLETE ===" << std::endl;
	return 0;
}
