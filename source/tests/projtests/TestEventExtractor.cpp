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

TEST(EventExtractor, CreatesBirthAndDeathEventsFromASinglePerson)
{
	PeopleDataCollection people;
	people.push_back(PeopleData("Mr. Sanders", 1926, 1961, id1));

	EventExtractor extractor;
	ImportantEvents events = extractor.convert(people);

	ASSERT_THAT(events.size(), Eq(2));
	EXPECT_THAT(events.at(0).id, Eq(id1));
	EXPECT_THAT(events.at(0).year, Eq(1926));
	EXPECT_THAT(events.at(0).eventType, Eq(BIRTH_EVENT));
	EXPECT_THAT(events.at(1).id, Eq(id1));
	EXPECT_THAT(events.at(1).year, Eq(1961));
	EXPECT_THAT(events.at(1).eventType, Eq(DEATH_EVENT));
}

TEST(EventExtractor, CreatesEventsFromMultiplePeople)
{
	PeopleDataCollection people;
	people.push_back(PeopleData("Mr. Sanders", 1926, 1961, id1));
	people.push_back(PeopleData("A. A. Milne", 1900, 1956, id2));
	people.push_back(PeopleData("Julie Andrews", 1935, 2000, id3));

	EventExtractor extractor;
	ImportantEvents events = extractor.convert(people);

	ASSERT_THAT(events.size(), Eq(6));
	EXPECT_THAT(events.at(0).id, Eq(id1));
	EXPECT_THAT(events.at(0).year, Eq(1926));
	EXPECT_THAT(events.at(0).eventType, Eq(BIRTH_EVENT));
	EXPECT_THAT(events.at(1).id, Eq(id1));
	EXPECT_THAT(events.at(1).year, Eq(1961));
	EXPECT_THAT(events.at(1).eventType, Eq(DEATH_EVENT));

	EXPECT_THAT(events.at(2).id, Eq(id2));
	EXPECT_THAT(events.at(2).year, Eq(1900));
	EXPECT_THAT(events.at(2).eventType, Eq(BIRTH_EVENT));
	EXPECT_THAT(events.at(3).id, Eq(id2));
	EXPECT_THAT(events.at(3).year, Eq(1956));
	EXPECT_THAT(events.at(3).eventType, Eq(DEATH_EVENT));

	EXPECT_THAT(events.at(4).id, Eq(id3));
	EXPECT_THAT(events.at(4).year, Eq(1935));
	EXPECT_THAT(events.at(4).eventType, Eq(BIRTH_EVENT));
	EXPECT_THAT(events.at(5).id, Eq(id3));
	EXPECT_THAT(events.at(5).year, Eq(2000));
	EXPECT_THAT(events.at(5).eventType, Eq(DEATH_EVENT));
}
