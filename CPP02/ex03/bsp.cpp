/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:21:29 by abillote          #+#    #+#             */
/*   Updated: 2025/07/19 16:05:22 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*Using Barycentric Coordinates approach
- A, B and C vertexes have a weigth on C
- If the 3 weight > 0 => point C is in the triangle
- If one of the weight < 0 => point C is outside of the triangle
- If one of the weigth = 0 => point C is on a vertex or an edge
*/
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ax = a.getX();
	Fixed ay = a.getY();
	Fixed bx = b.getX();
	Fixed by = b.getY();
	Fixed cx = c.getX();
	Fixed cy = c.getY();
	Fixed px = point.getX();
	Fixed py = point.getY();

	//Calculate the denominator for the weight calculation
	//Cross Product of Vector AB * Vector AC => area of the parallelogram that they form so twice the ABC triangle area
	//We keep it *2 so we don't have to divide it later

	Fixed denominator = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);

	//If denominator = 0, all points are colinear
	if (denominator == Fixed(0))
	{
		return (false);
	}

	//Calculate the weight :
	//Ex for w1: area of the parallelogram formed by PBC / area of the parallelogram formed by ABC
	// Cross product of PB * PC / denominator
	// If one of the weigth < 0, it means that the triangle formed with P has a reversed orientation, so P is outside ABC
	Fixed wA = ((bx - px) * (cy - py) - (cx - px) * (by - py)) / denominator;

	//Weight B = cross product of PC * PA / denominator
	Fixed wB = ((cx - px) * (ay - py) - (ax - px) * (cy - py)) / denominator;

	//Sum of the 3 weights must be equal to 1
	Fixed wC = Fixed(1) - wA - wB;

	return (wA > Fixed(0) && wB > Fixed(0) && wC > Fixed(0));

}
