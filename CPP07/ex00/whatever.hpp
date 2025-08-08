/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:10:55 by abillote          #+#    #+#             */
/*   Updated: 2025/08/08 17:50:23 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& arg1, T& arg2)
{
	T temp;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
T min(const T& arg1, const T& arg2)
{
	return arg1 < arg2 ? arg1 : arg2;
}

template <typename T>
T max(const T& arg1, const T& arg2)
{
	return arg1 > arg2 ? arg1 : arg2;
}

#endif
