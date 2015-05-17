#include "PeopleData.h"

PeopleData::PeopleData(std::string name_, int birthYear_, int deathYear_, PersonID uniqueID_) : 
	name(name_),
	birthYear(birthYear_),
	deathYear(deathYear_),
	id(uniqueID_)
{
}

PeopleData::~PeopleData()
{
}
