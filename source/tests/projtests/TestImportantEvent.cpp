/*
    Copyright 2015 Gianfranco Berardi. 

 	This file is part of the CodingChallengeForWI.

    The CodingChallengeForWI is free software: 
	you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CodingChallengeForWI is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CodingChallengeForWI.  If not, see <http://www.gnu.org/licenses/>.
 */

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

TEST(ImportantEvent, GivenTheSameYearBetweenEventsThenSortsByEventType)
{
	ImportantEvent event1(1999, BIRTH_EVENT, id1);
	ImportantEvent event2(1999, DEATH_EVENT, id2);

	EXPECT_TRUE(event1 < event2);
	EXPECT_FALSE(event2 < event1);
}
