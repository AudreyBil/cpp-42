/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:12:30 by abillote          #+#    #+#             */
/*   Updated: 2025/08/15 14:50:06 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

};

BitcoinExchange::BitcoinExchange(const std::string& dataFilename)
{
	BitcoinExchange::loadDatabase(dataFilename);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	m_exchangeRateMap = other.m_exchangeRateMap;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		m_exchangeRateMap = other.m_exchangeRateMap;
	}
	return *this;
};

BitcoinExchange::~BitcoinExchange()
{

};

void BitcoinExchange::parseDataLine(const std::string& line)
{
	size_t pos = line.find(",");
	if (pos != std::string::npos)
	{
		std::string date = line.substr(0, pos);
		std::string rateString = line.substr(pos + 1);
		double rate = std::atof(rateString.c_str());
		m_exchangeRateMap[date] = rate;
	}
}

void BitcoinExchange::loadDatabase(const std::string& dataFilename)
{
	std::ifstream dataFile(dataFilename.c_str());
	if (!dataFile.is_open()) {
		throw std::runtime_error("Could not open data file\n");
	}

	std::string line;
	bool firstline = true;
	while (getline(dataFile, line)) {
		if (firstline){
			firstline = false;
			continue;
		}
		BitcoinExchange::parseDataLine(line);
	}
	if (m_exchangeRateMap.size() == 0){
		throw CouldNotLoadDatabaseException();
	}
	dataFile.close();
}

void BitcoinExchange::parseInputLine(const std::string& line, std::string& dateInput, float& count)
{
	size_t pos = line.find('|');
	if (pos != std::string::npos)
	{
		dateInput = line.substr(0, pos - 1);
		if (pos + 1 < line.length())
		{
			std::string countStr = line.substr(pos + 2);
			const char* cCountstr = countStr.c_str();
			char* endptr;
			count = strtof(cCountstr, &endptr);
		}
		else
			count = -999999;
	}
	else
		dateInput = line;
}

void BitcoinExchange::processInputFile(const std::string& inputFilename)
{
	std::ifstream inputFile(inputFilename.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("could not open file\n");

	std::string dateInput;
	float count;
	std::string line;
	while (getline(inputFile, line)) {
		if (line.empty() || line.substr(0, 4) == "date")
			continue;
		BitcoinExchange::parseInputLine(line, dateInput, count);
		BitcoinExchange::printLine(dateInput, count);
	}
	inputFile.close();
}

bool BitcoinExchange::isDateNotInFuture(int inputYear, int inputMonth, int inputDay)
{
	time_t now = time(0);
	struct tm* currentTime = localtime(&now);
	int currentYear = currentTime->tm_year + 1900;
	int currentMonth = currentTime->tm_mon + 1;
	int currentDay = currentTime->tm_mday;

	if (inputYear > currentYear)
		return false;
	if (inputYear < currentYear)
		return true;
	if (inputMonth > currentMonth)
		return false;
	if (inputMonth < currentMonth)
		return true;
	if (inputDay > currentDay)
		return false;
	return true;
}

bool BitcoinExchange::validateDateInput(const std::string& dateInput)
{
	//Check format
	if (dateInput.length() != 10)
		return false;
	if (dateInput[4] != '-' || dateInput[7] != '-')
		return false;

	//Check Digits
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7)
			if (!std::isdigit(dateInput[i]))
				return false;
	}

	//Check date existence
	std::string year = dateInput.substr(0, 4);
	std::string month = dateInput.substr(5, 2);
	std::string day = dateInput.substr(8, 2);

	int yearNum = atoi(year.c_str());
	int monthNum = atoi(month.c_str());
	int dayNum = atoi(day.c_str());

	//Check Month
	if (monthNum < 1 || monthNum > 12)
		return false;

	// Check Days in month
	int daysinMonth;

	if (monthNum == 2) //Check leap year for feb
	{
		bool isLeapYear((yearNum % 4 == 0 && yearNum % 100 != 0) || yearNum % 400 == 0);
		daysinMonth = isLeapYear? 29:28;
	}
	else if (monthNum == 4 || monthNum == 6 || monthNum == 9 || monthNum == 11) {
		daysinMonth = 30;
	}
	else {
		daysinMonth = 31;
	}

	if (dayNum < 1 || dayNum > daysinMonth)
		return false;

	//Check Date not in past or future
	if (yearNum < 2009 || (yearNum == 2009 && monthNum == 01 && dayNum == 01))
		return false;
	if (!isDateNotInFuture(yearNum, monthNum, dayNum))
		return false;

	return true;
}

double BitcoinExchange::calculateValue(const std::string& date, double count)
{
	std::map<std::string, double>::iterator it = m_exchangeRateMap.find(date);
	if (it != m_exchangeRateMap.end()) {
		return it->second * count;
	}
	it = m_exchangeRateMap.upper_bound(date);
	--it;

	return it->second * count;
}

void BitcoinExchange::printLine(const std::string& dateInput, float count)
{
	if (!validateDateInput(dateInput))
		std::cout << "Error: bad input => " << dateInput << std::endl;
	else if (count == -999999)
		std::cout << "Error: missing value." << std::endl;
	else if (count < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (count > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else {
			double totalValue = BitcoinExchange::calculateValue(dateInput, count);
			std::cout << dateInput << " => " << count << " = " << totalValue << std::endl;
	}
}

const char* BitcoinExchange::CouldNotLoadDatabaseException::what() const throw()
{
	return "Could not load database\n";
}
