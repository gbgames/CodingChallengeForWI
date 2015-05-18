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
	return person.birthYear > m_beginRange;
}
