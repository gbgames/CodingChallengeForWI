#include "Parser.h"

#include "IDateValidator.h"
#include <sstream>
#include <string>

Parser::Parser()
{
}

Parser::~Parser()
{
}

PeopleDataCollection Parser::parse(std::istream & input, const IDateValidator & validator)
{
	PeopleDataCollection people;
	std::string currentLine;
	PersonID id = 1;
	while (std::getline(input, currentLine))
	{
		std::string name;
		size_t firstPosition = 0;
		size_t lastPosition = 0;
		if (!extractName(name, firstPosition, lastPosition, currentLine))
		{
			continue;
		}
		
		int birthYear(-1);
		firstPosition = lastPosition + 1;
		if (!extractBirthYear(birthYear, firstPosition, lastPosition, currentLine))
		{
			continue;
		}

		int deathYear(-1);
		firstPosition = lastPosition + 1;

	
		if (!extractDeathYear(deathYear, firstPosition, currentLine))
		{
			continue;
		}

		PeopleData person(name, birthYear, deathYear, id);
		if (validator.validate(person))
		{
			people.push_back(person);
			++id;
		}
	}

	return people;
}

bool Parser::extractName(std::string & name, size_t & firstPosition, size_t & lastPosition, const std::string & currentLine) const
{
	lastPosition = currentLine.find(',');
	if (lastPosition != std::string::npos)
	{
		name = currentLine.substr(firstPosition, lastPosition);
	}

	return std::string::npos != lastPosition;
}

bool Parser::extractBirthYear(int & birthYear, size_t & firstPosition, size_t & lastPosition, const std::string currentLine) const
{
	lastPosition = currentLine.find(',', firstPosition);
	if (lastPosition != std::string::npos)
	{
		std::stringstream birthYearText;
		birthYearText << currentLine.substr(firstPosition, lastPosition);
		birthYearText >> birthYear; 
		if (birthYearText.fail())
		{
			lastPosition = std::string::npos;
		}
	}

	return std::string::npos != lastPosition;
}

bool Parser::extractDeathYear(int & deathYear, size_t & firstPosition, const std::string currentLine) const
{
	bool deathYearExtracted(true);

	size_t lastPosition = currentLine.find(',', firstPosition);
	if (std::string::npos == lastPosition)
	{
		std::stringstream deathYearText;
		deathYearText << currentLine.substr(firstPosition, std::string::npos);
		deathYearText >> deathYear; 
		if (deathYearText.fail())
		{
			deathYearExtracted = false;
		}
	}
	else
	{
		deathYearExtracted = false;
	}

	return deathYearExtracted;
}
