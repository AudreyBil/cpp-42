/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:53:20 by abillote          #+#    #+#             */
/*   Updated: 2025/08/12 11:53:12 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cctype>
#include <vector>
#include <iterator>
#include <algorithm>
#include <climits>

class Span {
	public:
		//Constructors
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);

		//Destructor
		~Span();

		//Member functions
		void addNumber(int number);

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);

		int shortestSpan() const;
		int longestSpan() const;

		//Getter
		unsigned int getSize();

		//Exceptions
		class StorageFullException : public std::exception {
			virtual const char* what() const throw();
		};
		class NotEnoughIntegersException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		unsigned int m_capacity;
		std::vector<int> m_storage;
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	size_t rangeSize = std::distance(begin, end);
	if (m_storage.size() + rangeSize > m_capacity)
		throw StorageFullException();
	m_storage.insert(m_storage.end(), begin, end);
}

#endif
