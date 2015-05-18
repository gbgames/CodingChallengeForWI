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

TEST(Parser, CreatesPeopleDataFromMultipleLinesOfData)
{
	std::string name1 = "Mario Mario";
	int birthYear1 = 1981;
	int deathYear1 = 2000;
	std::string name2 = "Luigi Mario";
	int birthYear2 = 1983;
	int deathYear2 = 1999;
	std::string name3 = "Evil Otto";
	int birthYear3 = 1980;
	int deathYear3 = 1984;

	std::stringstream fakeFile;
	fakeFile << name1 << "," << birthYear1 << "," << deathYear1 << std::endl;
	fakeFile << name2 << "," << birthYear2 << "," << deathYear2 << std::endl;
	fakeFile << name3 << "," << birthYear3 << "," << deathYear3; 

	Parser parser;
	PeopleDataCollection people = parser.parse(fakeFile);

	ASSERT_THAT(people.size(), Eq(3));
	EXPECT_THAT(people.at(0).name, StrEq(name1));
	EXPECT_THAT(people.at(0).birthYear, Eq(birthYear1));
	EXPECT_THAT(people.at(0).deathYear, Eq(deathYear1));

	EXPECT_THAT(people.at(1).name, StrEq(name2));
	EXPECT_THAT(people.at(1).birthYear, Eq(birthYear2));
	EXPECT_THAT(people.at(1).deathYear, Eq(deathYear2));

	EXPECT_THAT(people.at(2).name, StrEq(name3));
	EXPECT_THAT(people.at(2).birthYear, Eq(birthYear3));
	EXPECT_THAT(people.at(2).deathYear, Eq(deathYear3));
}
