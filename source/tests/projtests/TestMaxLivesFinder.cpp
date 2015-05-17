#include "MaxLivesFinder.h"

#include "gmock/gmock-matchers.h"

using namespace EVENT;
using namespace ::testing;

namespace 
{
	PersonID id1(1);
	PersonID id2(2);
}

class MaxLivesFinderFixture : public Test
{
	public:
		MaxLivesFinderFixture()
		{
		}
		~MaxLivesFinderFixture()
		{
		}
	
		ImportantEvents events;
		MaxLivesFinder finder;
};

TEST_F(MaxLivesFinderFixture, GivenASingleBirthEventReturnYearAndIDOfEvent)
{
	events.push_back(ImportantEvent(1999, BIRTH_EVENT, id1));
	MaxLivesResult result = finder.searchEvents(events);

	EXPECT_THAT(result.earliestYear, Eq(1999));
	ASSERT_THAT(result.idCollection.size(), Eq(1));
	EXPECT_THAT(result.idCollection.at(0), Eq(id1));
}

TEST_F(MaxLivesFinderFixture, GivenTwoBirthEventsReturnYearInWhichBothIDsAreAlive)
{
	events.push_back(ImportantEvent(1999, BIRTH_EVENT, id1));
	events.push_back(ImportantEvent(2000, BIRTH_EVENT, id2));
	MaxLivesResult result = finder.searchEvents(events);

	EXPECT_THAT(result.earliestYear, Eq(2000));
	ASSERT_THAT(result.idCollection.size(), Eq(2));
	EXPECT_THAT(result.idCollection.at(0), Eq(id1));
	EXPECT_THAT(result.idCollection.at(1), Eq(id2));
}
