#ifndef GB_PARSER_H
#define GB_PARSER_H

#include "PeopleData.h"
#include <iosfwd>

class Parser
{
	public:
		Parser();
		~Parser();

		PeopleDataCollection parse(std::istream & input);
	
	private:
		bool extractName(std::string & name, size_t & firstPosition, size_t & lastPosition, const std::string & currentLine) const;
		bool extractBirthYear(int & birthYear, size_t & firstPosition, size_t & lastPosition, const std::string currentLine) const;
		bool extractDeathYear(int & deathYear, size_t & firstPosition, const std::string currentLine) const;
};

#endif
