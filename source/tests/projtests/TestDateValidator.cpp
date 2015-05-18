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
