/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:53:20 by abillote          #+#    #+#             */
/*   Updated: 2025/08/08 17:34:31 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cctype>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int i);
		T const& operator[](unsigned int i) const;
		class IndexOutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		unsigned int size() const;

	private:
		T *m_array;
		unsigned int m_size;
};

template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0) {
	m_array = new T[0];
};

template <typename T>
Array<T>::Array(unsigned int n) : m_array(NULL), m_size(n) {
	m_array = new T[n];

};

template <typename T>
Array<T>::Array(const Array& other) : m_size(other.m_size) {
	m_array = new T[m_size];
	for (unsigned int i = 0; i < m_size; i++)
			m_array[i] = other.m_array[i];
};

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other)
	{
		delete [] m_array;
		m_size = other.m_size;
		m_array = new T[m_size];
		for (unsigned int i = 0; i < m_size; i++)
			m_array[i] = other.m_array[i];
	}
	return *this;
};

template <typename T>
Array<T>::~Array() {
	delete [] m_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= m_size)
		throw IndexOutOfBoundsException();
	return m_array[i];
}

template <typename T>
T const& Array<T>::operator[](unsigned int i) const
{
	if (i >= m_size)
		throw IndexOutOfBoundsException();
	return m_array[i];
}


template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Index is out of bounds";
}

template <typename T>
unsigned int Array<T>::size() const
{
	return m_size;
}


#endif
