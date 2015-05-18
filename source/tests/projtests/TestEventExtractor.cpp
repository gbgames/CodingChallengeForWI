#include "EventExtractor.h"

#include "gmock/gmock-matchers.h"

using namespace EVENT;
using namespace ::testing;

namespace 
{
	PersonID id1(1);
	PersonID id2(2);
	PersonID id3(3);
}

class EventExtractorFixture: public Test
{
	public:
	EventExtractorFixture()
	{
	}
	~EventExtractorFixture()
	{
	}

	PeopleDataCollection people;
	EventExtractor extractor;
	ImportantEvents events;

	void verifyEvent(const PeopleData & person, unsigned int eventIndex, EVENT::Type eventType)
	{
		ASSERT_THAT(events.size(), Ge(eventIndex));
		const ImportantEvent &  event = events.at(eventIndex);
		EXPECT_THAT(event.id, Eq(person.id));
		EXPECT_THAT(event.eventType, Eq(eventType));
		int relevantYear = person.birthYear;
		if (eventType == DEATH_EVENT)
		{
			relevantYear = person.deathYear;
		}
		EXPECT_THAT(event.year, Eq(relevantYear));
	}
};

TEST_F(EventExtractorFixture, CreatesBirthAndDeathEventsFromASinglePerson)
{
	people.push_back(PeopleData("Mr. Sanders", 1926, 1961, id1));

	events = extractor.convert(people);

	verifyEvent(people.back(), 0, BIRTH_EVENT);
	verifyEvent(people.back(), 1, DEATH_EVENT);
}

TEST_F(EventExtractorFixture, CreatesEventsFromMultiplePeople)
{
	people.push_back(PeopleData("Mr. Sanders", 1926, 1961, id1));
	people.push_back(PeopleData("A. A. Milne", 1900, 1956, id2));
	people.push_back(PeopleData("Julie Andrews", 1935, 2000, id3));

	events = extractor.convert(people);

	verifyEvent(people.at(0), 0, BIRTH_EVENT);
	verifyEvent(people.at(0), 1, DEATH_EVENT);

	verifyEvent(people.at(1), 2, BIRTH_EVENT);
	verifyEvent(people.at(1), 3, DEATH_EVENT);

	verifyEvent(people.at(2), 4, BIRTH_EVENT);
	verifyEvent(people.at(2), 5, DEATH_EVENT);
}
