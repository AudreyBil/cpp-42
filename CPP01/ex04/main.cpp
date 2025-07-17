/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:58:56 by abillote          #+#    #+#             */
/*   Updated: 2025/07/17 10:44:11 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replaceString(std::ifstream& inputFile, std::ofstream& outputFile,
					const std::string& s1, const std::string& s2)
{
	std::string line;

	while (getline(inputFile, line))
	{
		std::string newLine = "";
		size_t pos = 0;
		size_t found = 0;

		while ((found = line.find(s1, pos)) != std::string::npos)
		{
			newLine += line.substr(pos, found - pos);
			newLine += s2;
			pos = found + s1.length();
		}
		newLine += line.substr(pos);
		outputFile << newLine << std::endl;
	}
}


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error. Wrong number of arguments.\n";
		return 1;
	}

	std::string inputFilename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inputFile(inputFilename.c_str());
	if (!inputFile.is_open())
	{
		std::cout << "Error. Cannot open the input file.";
		return 1;
	}

	std::string outputFilename = inputFilename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cout << "Error. Cannot open the output file.";
		return 1;
	}

	replaceString(inputFile, outputFile, s1, s2);

	inputFile.close();
	outputFile.close();
	return 0;
}
