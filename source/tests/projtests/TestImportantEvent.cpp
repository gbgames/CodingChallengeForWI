#include "ImportantEvent.h"

#include "gtest/gtest.h"

using namespace EVENT;

namespace
{
	PersonID id1(1);
	PersonID id2(2);
}

TEST(ImportantEvent, SortsByYear)
{
	ImportantEvent event1(1999, BIRTH_EVENT, id1);
	ImportantEvent event2(2000, BIRTH_EVENT, id2);

	EXPECT_TRUE(event1 < event2);
	EXPECT_FALSE(event2 < event1);
}
