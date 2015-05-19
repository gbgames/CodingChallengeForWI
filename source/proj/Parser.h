/*
    Copyright 2015 Gianfranco Berardi. 

 	This file is part of the CodingChallengeForWI.

    The CodingChallengeForWI is free software: 
	you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CodingChallengeForWI is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CodingChallengeForWI.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GB_PARSER_H
#define GB_PARSER_H

#include "PeopleData.h"
#include <iosfwd>

class IDateValidator;

class Parser
{
	public:
		Parser();
		~Parser();

		PeopleDataCollection parse(std::istream & input, const IDateValidator & validator);
	
	private:
		bool extractName(std::string & name, size_t & firstPosition, size_t & lastPosition, const std::string & currentLine) const;
		bool extractBirthYear(int & birthYear, size_t & firstPosition, size_t & lastPosition, const std::string currentLine) const;
		bool extractDeathYear(int & deathYear, size_t & firstPosition, const std::string currentLine) const;
};

#endif
