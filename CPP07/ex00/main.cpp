/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:13:58 by abillote          #+#    #+#             */
/*   Updated: 2025/08/08 17:50:13 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {

	std::cout << "---Test integers---\n";
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

	std::cout << "\n---Test strings---\n";
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;

	std::cout << "\n---Test equal values---\n";
	int x = 5;
	int y = 5;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	std::cout << "\n---Test floats---\n";
	float f1 = 3.14f;
	float f2 = 2.71f;
	::swap(f1, f2);
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
	std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;

	std::cout << "\n---Test chars---\n";
	char ch1 = 'a';
	char ch2 = 'z';
	::swap(ch1, ch2);
	std::cout << "ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
	std::cout << "min(ch1, ch2) = " << ::min(ch1, ch2) << std::endl;
	std::cout << "max(ch1, ch2) = " << ::max(ch1, ch2) << std::endl;

	return 0;
}

