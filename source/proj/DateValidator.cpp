#include "DateValidator.h"

#include "PeopleData.h"

DateValidator::DateValidator(int startYear, int endYear) : 
	m_beginRange(startYear),
	m_endRange(endYear)
{
}

DateValidator::~DateValidator()
{
}

bool DateValidator::validate(PeopleData & person) const
{
	bool personBornWithinRange(person.birthYear >= m_beginRange && person.birthYear <= m_endRange); 
	bool personDiedWithinRange(person.deathYear <= m_endRange);

	return personBornWithinRange && personDiedWithinRange;
}
