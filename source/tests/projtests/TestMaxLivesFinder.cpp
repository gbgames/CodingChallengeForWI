#include "MaxLivesFinder.h"

#include "gmock/gmock-matchers.h"

using namespace EVENT;
using namespace ::testing;

namespace 
{
	PersonID id1(1);
}

TEST(MaxLivesFinder, GivenASingleBirthEventReturnYearAndIDOfEvent)
{
	ImportantEvents events;
	events.push_back(ImportantEvent(1999, BIRTH_EVENT, id1));
	MaxLivesFinder finder;
	MaxLivesResult result = finder.searchEvents(events);

	EXPECT_THAT(result.earliestYear, Eq(1999));
	ASSERT_THAT(result.idCollection.size(), Eq(1));
	EXPECT_THAT(result.idCollection.at(0), Eq(id1));
}
