#include "ImportantEvent.h"

ImportantEvent::ImportantEvent(int year_, EVENT::Type eventType_, PersonID identifier_) : 
	year(year_),
	eventType(eventType_),
	id(identifier_)
{
}

ImportantEvent::~ImportantEvent()
{
}

bool ImportantEvent::operator<(const ImportantEvent & rhs) const
{
	return this->year < rhs.year;
}
