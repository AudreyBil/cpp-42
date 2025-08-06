/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:34:33 by abillote          #+#    #+#             */
/*   Updated: 2025/08/06 16:45:42 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
		static void convert(const std::string& str);
};

enum DataType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

DataType determineType(const std::string& str);
void convertChar(const std::string& str);
void convertInt(const std::string& str);
void convertFloat(const std::string& str);
void convertDouble(const std::string& str);

bool isSpecialCase(const std::string& str);
void handleSpecialCase(const std::string& str);


#endif
