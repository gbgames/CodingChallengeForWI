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
};

#endif
