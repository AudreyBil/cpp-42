/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:18:50 by abillote          #+#    #+#             */
/*   Updated: 2025/07/19 16:04:36 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0), y(0)
{

};

Point::Point(const float x_val, const float y_val)
:x(x_val), y(y_val)
{

};

Point::Point(const Point& other)
:x(other.x), y(other.y)
{

};


Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	return *this;
};


Point::~Point()
{

};

Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}
