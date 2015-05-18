#include "Parser.h"

#include <sstream>
#include "gmock/gmock-matchers.h"

using namespace ::testing;

TEST(Parser, CreatesPeopleDataFromSingleLineOfData)
{
	std::string name = "Mario Mario";
	int birthYear = 1981;
	int deathYear = 2000;

	std::stringstream fakeFile;
	fakeFile << name << "," << birthYear << "," << deathYear;

	Parser parser;
	PeopleDataCollection people = parser.parse(fakeFile);

	ASSERT_THAT(people.size(), Eq(1));
	EXPECT_THAT(people.at(0).name, StrEq(name));
	EXPECT_THAT(people.at(0).birthYear, Eq(birthYear));
	EXPECT_THAT(people.at(0).deathYear, Eq(deathYear));
}
