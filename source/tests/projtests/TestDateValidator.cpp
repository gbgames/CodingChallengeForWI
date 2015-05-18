#include "DateValidator.h"

#include "PeopleData.h"
#include "gtest/gtest.h"

TEST(DateValidator, AcceptsPersonWithLifeInSpecifiedRange)
{
	DateValidator validator(1900, 2000);
	PeopleData person("Veronica Lake", 1922, 1973, 1);

	EXPECT_TRUE(validator.validate(person));
}

TEST(DateValidator, RejectsPersonWhoWasBornBeforeSpecifiedRange)
{
	DateValidator validator(1900, 2000);
	PeopleData person("Abraham Lincoln", 1809, 1865, 1);

	EXPECT_FALSE(validator.validate(person));
}
