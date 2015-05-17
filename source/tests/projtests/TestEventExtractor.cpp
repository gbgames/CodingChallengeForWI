#include "EventExtractor.h"

#include "gmock/gmock-matchers.h"

using namespace EVENT;
using namespace ::testing;

namespace 
{
	PersonID id1(1);
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
