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
