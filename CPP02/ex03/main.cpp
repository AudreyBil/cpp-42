/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:40:03 by abillote          #+#    #+#             */
/*   Updated: 2025/07/19 16:09:02 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

# include <iostream>

int main() {

	std::cout << "=== BSP Triangle Inside Test ===" << std::endl;

	// Define a simple triangle
	Point a(0.0f, 0.0f);	  // Bottom-left
	Point b(10.0f, 0.0f);	 // Bottom-right
	Point c(5.0f, 10.0f);	 // Top

	// Test points inside the triangle
	Point inside1(5.0f, 2.0f);	// Should be inside
	Point inside2(3.0f, 1.0f);	// Should be inside
	Point inside3(7.0f, 3.0f);	// Should be inside

	// Test points outside the triangle
	Point outside1(-1.0f, 0.0f);  // Left of triangle
	Point outside2(15.0f, 0.0f);  // Right of triangle
	Point outside3(5.0f, 15.0f);  // Above triangle
	Point outside4(5.0f, -1.0f);  // Below triangle

	// Test points on vertices (should return false)
	Point vertex1(0.0f, 0.0f);	// Vertex A
	Point vertex2(10.0f, 0.0f);   // Vertex B
	Point vertex3(5.0f, 10.0f);   // Vertex C

	// Test points on edges (should return false)
	Point edge1(5.0f, 0.0f);	  // On bottom edge
	Point edge2(2.5f, 5.0f);	  // On left edge
	Point edge3(7.5f, 5.0f);	  // On right edge

	// Run tests
	std::cout << "Define Triangle:\n";
	std::cout << "Point A (" << a.getX() << "," << a.getY() << ")\n";
	std::cout << "Point B (" << b.getX() << "," << b.getY() << ")\n";
	std::cout << "Point c (" << c.getX() << "," << c.getY() << ")\n";


	std::cout << "\nPoints inside triangle:" << std::endl;
	std::cout << "inside1 (5,2): " << (bsp(a, b, c, inside1) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "inside2 (3,1): " << (bsp(a, b, c, inside2) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "inside3 (7,3): " << (bsp(a, b, c, inside3) ? "TRUE" : "FALSE") << std::endl;

	std::cout << "\nPoints outside triangle:" << std::endl;
	std::cout << "outside1 (-1,0): " << (bsp(a, b, c, outside1) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "outside2 (15,0): " << (bsp(a, b, c, outside2) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "outside3 (5,15): " << (bsp(a, b, c, outside3) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "outside4 (5,-1): " << (bsp(a, b, c, outside4) ? "TRUE" : "FALSE") << std::endl;

	std::cout << "\nPoints on vertices (should be FALSE):" << std::endl;
	std::cout << "vertex A (0,0): " << (bsp(a, b, c, vertex1) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "vertex B (10,0): " << (bsp(a, b, c, vertex2) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "vertex C (5,10): " << (bsp(a, b, c, vertex3) ? "TRUE" : "FALSE") << std::endl;

	std::cout << "\nPoints on edges (should be FALSE):" << std::endl;
	std::cout << "edge1 (5,0): " << (bsp(a, b, c, edge1) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "edge2 (2.5,5): " << (bsp(a, b, c, edge2) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "edge3 (7.5,5): " << (bsp(a, b, c, edge3) ? "TRUE" : "FALSE") << std::endl;

	std::cout << "\n=== Test Complete ===" << std::endl;
	return 0;
}
