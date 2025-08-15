/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:12:44 by abillote          #+#    #+#             */
/*   Updated: 2025/08/15 14:55:57 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <iomanip>

/*Create BitCoinExchange Class*/

class BitcoinExchange {
	public:
		//Constructors
		BitcoinExchange();
		BitcoinExchange(const std::string& dataFilename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		//Member functions
		void loadDatabase(const std::string& dataFilename); //Load exchange rate map
		double calculateValue(const std::string& date, double count); //Calculate value based on date and nb of bitcoin from input file
		void processInputFile(const std::string& inputFilename); //Read file line by line and output date + value for each line (+ errors)

	private:
		std::map<std::string, double> m_exchangeRateMap;

		void printLine(const std::string& dateInput, float count);

		// Utility functions:
		void parseDataLine(const std::string& line);
		static void parseInputLine (const std::string& line, std::string& dateInput, float& count);
		static bool validateDateInput(const std::string& dateInput);
		static bool isDateNotInFuture(int year, int month, int day);

		//Exceptions
		class CouldNotLoadDatabaseException : public std::exception {
			virtual const char* what() const throw();
		};

};

#endif
