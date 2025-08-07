/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:34:11 by abillote          #+#    #+#             */
/*   Updated: 2025/08/07 10:04:51 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{

};
ScalarConverter::ScalarConverter(const ScalarConverter& /*other*/)
{

};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& /*other*/)
{
	return *this;
};

ScalarConverter::~ScalarConverter()
{

};

void ScalarConverter::convert(const std::string& str)
{
	DataType DataType;

	if (str.empty())
	{
		std::cout << "Input can not be empty\n";
		return ;
	}

	if (isSpecialCase(str))
	{
		handleSpecialCase(str);
		return ;
	}

	DataType = determineType(str);

	switch (DataType)
	{
	case CHAR: {
		convertChar(str);
		break;
	}
	case INT: {
		convertInt(str);
		break;
	}
	case FLOAT: {
		convertFloat(str);
		break;
	}
	case DOUBLE: {
		convertDouble(str);
		break;
	}
	case UNKNOWN: {
		std::cout << "This conversion is not possible as this type is unknown.\n";
		break;
	}
	default:
		break;
	}
}
