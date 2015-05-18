#include "Parser.h"

#include <sstream>
#include <string>

Parser::Parser()
{
}

Parser::~Parser()
{
}

PeopleDataCollection Parser::parse(std::istream & input)
{
	PeopleDataCollection people;
	std::string currentLine;
	PersonID id = 1;
	while (std::getline(input, currentLine))
	{
		std::string name;
		size_t firstPosition = 0;
		size_t lastPosition = currentLine.find(',');
		if (lastPosition != std::string::npos)
		{
			name = currentLine.substr(firstPosition, lastPosition);
		}
		
		int birthYear(-1);
		firstPosition = lastPosition + 1;
		lastPosition = currentLine.find(',', lastPosition + 1);
		if (lastPosition != std::string::npos)
		{
			std::string birthYearText = currentLine.substr(firstPosition, lastPosition);
			std::istringstream(birthYearText) >> birthYear; 
		}

		int deathYear(-1);
		firstPosition = lastPosition + 1;
		lastPosition = std::string::npos;
		std::string deathYearText = currentLine.substr(firstPosition, lastPosition);
		std::istringstream(deathYearText) >> deathYear; 

		people.push_back(PeopleData(name, birthYear, deathYear, id++));
	}

	return people;
}
