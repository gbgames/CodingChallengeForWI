#include "EventExtractor.h"

using namespace EVENT;

EventExtractor::EventExtractor()
{
}

EventExtractor::~EventExtractor()
{
}

ImportantEvents EventExtractor::convert(const PeopleDataCollection & people)
{
	ImportantEvents events;
	PeopleData person = people.at(0);
	events.push_back(ImportantEvent(person.birthYear, BIRTH_EVENT, person.id));
	events.push_back(ImportantEvent(person.deathYear, DEATH_EVENT, person.id));

	return events;
}
