/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:19:10 by abillote          #+#    #+#             */
/*   Updated: 2025/07/19 14:46:53 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:

		Point();
		Point(const float x_val, const float y_val);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
		Fixed getX() const;
		Fixed getY() const;

	private:
		const Fixed x;
		const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
