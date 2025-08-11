/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:53:20 by abillote          #+#    #+#             */
/*   Updated: 2025/08/11 17:22:08 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <cctype>
#include <vector>
#include <iterator>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Not Found");
		}
};

template <typename T>
typename T::iterator easyfind(T& arr, int toFind)
{
	typename T::iterator found;
	found = std::find(arr.begin(), arr.end(), toFind);
	if (found == arr.end())
	{
		throw NotFoundException();
	}
	else
		return found;
}

#endif
