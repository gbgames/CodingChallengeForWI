#ifndef GB_PEOPLE_DATA_H
#define GB_PEOPLE_DATA_H

#include "PersonID.h"
#include <string>

struct PeopleData
{
	PeopleData(std::string name_, int birthYear_, int deathYear_, PersonID uniqueID_);
	~PeopleData();
	std::string name;
	int birthYear;
	int deathYear;
	PersonID id;
};

typedef std::vector<PeopleData> PeopleDataCollection;

#endif
