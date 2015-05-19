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

#include "DateValidator.h"

#include "PeopleData.h"
#include "gtest/gtest.h"

using namespace ::testing;

class DateValidatorFixture : public Test
{
	public:
		DateValidatorFixture() : validator(1900, 2000)
		{
		}
		~DateValidatorFixture() {}
	
		DateValidator validator;
};

TEST_F(DateValidatorFixture, AcceptsPersonWithLifeInSpecifiedRange)
{
	PeopleData person("Veronica Lake", 1922, 1973, 1);

	EXPECT_TRUE(validator.validate(person));
}

TEST_F(DateValidatorFixture, RejectsPersonWhoWasBornBeforeSpecifiedRange)
{
	PeopleData person("Abraham Lincoln", 1809, 1865, 1);

	EXPECT_FALSE(validator.validate(person));
}

TEST_F(DateValidatorFixture, RejectsPersonWhoWasBornAfterSpecifiedRange)
{
	PeopleData person("Rowan Blanchard", 2001, 2091, 1);
	
	EXPECT_FALSE(validator.validate(person));
}

TEST_F(DateValidatorFixture, AcceptsPeopleBornAtExtremesOfRange)
{
	PeopleData infant("Baby", 2000, 2000, 1);
	PeopleData centenarian("Senior citizen", 1900, 2000, 2);

	EXPECT_TRUE(validator.validate(infant));
	EXPECT_TRUE(validator.validate(centenarian));
}

TEST_F(DateValidatorFixture, RejectsPersonWhoDiedAfterSpecifiedRange)
{
	PeopleData tooRecentDeath("Bob Hoskins", 1942, 2014, 1);

	EXPECT_FALSE(validator.validate(tooRecentDeath));
}

TEST_F(DateValidatorFixture, RejectsTimeTravelers)
{
	PeopleData heyMcFlyIThoughtIToldYouNeverToComeInHereAgain("Marty McFly", 1985, 1955, 1);

	EXPECT_FALSE(validator.validate(heyMcFlyIThoughtIToldYouNeverToComeInHereAgain));
}
