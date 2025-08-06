/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:08:19 by abillote          #+#    #+#             */
/*   Updated: 2025/08/06 17:38:04 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

DataType determineType(const std::string& str)
{
	//Check if Char
	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return FLOAT;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return DOUBLE;

	const char* cstr = str.c_str();
	char* endptr;

	//Cleaning errno from previous errors
	errno = 0;

	//Try to parse as int with strtol
	long longValue = std::strtol(cstr, &endptr, 10);
	if (*endptr == '\0' && errno == 0)
	{
		if (longValue >= std::numeric_limits<int>::min()
			&& longValue <= std::numeric_limits<int>::max())
		{
			return INT;
		}
	}

	//Cleaning errno from previous errors
	errno = 0;

	//Try to parse as double with strtod()
	std::strtod(cstr, &endptr);
	if (*endptr == '\0' && errno == 0)
	{
		return DOUBLE;
	}
	if (*endptr == 'f' && errno == 0) {
		std::strtof(cstr, &endptr);
		if (*endptr == 'f' && errno == 0)
			return FLOAT;
	}

	return UNKNOWN;
}

void convertChar(const std::string& str)
{
	char c = str[0];
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertInt(const std::string& str)
{
	const char* cstr = str.c_str();
	int originalvalue = std::atoi(cstr);
	bool tolerance = false;
	if (std::fabs(originalvalue) < 1e6) {
		tolerance = std::fabs(originalvalue - static_cast<int>(originalvalue)) < 0.0000000000001;
	}

	if (originalvalue < 32 || originalvalue > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(originalvalue) << "'" << std::endl;
	std::cout << "int: " << originalvalue << std::endl;
	std::cout << "float: " << static_cast<float>(originalvalue) << (tolerance ? ".0f" : "f" ) << std::endl;
	std::cout << "double: " << static_cast<double>(originalvalue) << (tolerance ? ".0" : "" ) << std::endl;
}

void convertFloat(const std::string& str)
{
	const char* cstr = str.c_str();
	char* endptr;
	float originalvalue = std::strtof(cstr, &endptr);
	bool tolerance = false;
	if (std::fabs(originalvalue) < 1e6) {
		tolerance = std::fabs(originalvalue - static_cast<int>(originalvalue)) < 0.0000000000001;
	}

	if (originalvalue < 32 || originalvalue > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(originalvalue) << "'" << std::endl;

	if(originalvalue < std::numeric_limits<int>::min() ||
		originalvalue > std::numeric_limits<int>::max())
		std::cout << "int: Non displayable because of overflow or underflow.\n";
	else
		std::cout << "int: " << static_cast<int>(originalvalue) << std::endl;

	std::cout << "float: " << originalvalue << (tolerance ? ".0f" : "f" ) << std::endl;
	std::cout << "double: " << static_cast<double>(originalvalue) << (tolerance ? ".0" : "" ) << std::endl;
}

void convertDouble(const std::string& str)
{
	const char* cstr = str.c_str();
	char* endptr;
	double originalvalue = std::strtod(cstr, &endptr);
	bool tolerance = false;
	if (std::fabs(originalvalue) < 1e6) {
		tolerance = std::fabs(originalvalue - static_cast<int>(originalvalue)) < 0.0000000000001;
	}
	if (originalvalue < 32 || originalvalue > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(originalvalue) << "'" << std::endl;

	if(originalvalue < std::numeric_limits<int>::min() ||
		originalvalue > std::numeric_limits<int>::max())
		std::cout << "int: Non displayable because of overflow or underflow.\n";
	else
		std::cout << "int: " << static_cast<int>(originalvalue) << std::endl;

	if(originalvalue < -std::numeric_limits<float>::max() ||
		originalvalue > std::numeric_limits<float>::max())
		std::cout << "float: Non displayable because of overflow or underflow.\n";
	else
		std::cout << "float: " << static_cast<float>(originalvalue) << (tolerance ? ".0f" : "f" ) << std::endl;

	std::cout << "double: " << originalvalue << (tolerance ? ".0" : "" ) << std::endl;
}

bool isSpecialCase(const std::string& str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return 1;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return 1;

	return 0;
}

void handleSpecialCase(const std::string& str)
{
	if (str == "nanf" || str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}
