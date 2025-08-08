/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:10:55 by abillote          #+#    #+#             */
/*   Updated: 2025/08/08 18:05:11 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cctype>

template <typename ArrayType, typename SizeType, typename FunctionType>
void iter(ArrayType* array, SizeType length, FunctionType func)
{
	if (array == NULL)
		return;
	for (SizeType i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename ArrayType, typename SizeType, typename FunctionType>
void iter(const ArrayType* array, SizeType length, FunctionType func)
{
	if (array == NULL)
		return;
	for (SizeType i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void printConst(const T& element)
{
	std::cout << "Printing the array element (const): " << element << std::endl;
}
template <typename T>
void printNonConst(T& element)
{
	std::cout << "Printing the array element (non-const):: " << element << std::endl;
}

#endif
