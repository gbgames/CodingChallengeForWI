#include "Parser.h"

#include <sstream>
#include "gmock/gmock-matchers.h"

using namespace ::testing;

namespace
{
	const std::string name1 = "Mario Mario";
	const int birthYear1 = 1981;
	const int deathYear1 = 2000;

	const std::string name2 = "Luigi Mario";
	const int birthYear2 = 1983;
	const int deathYear2 = 1999;

	const std::string name3 = "Evil Otto";
	const int birthYear3 = 1980;
	const int deathYear3 = 1984;
}

class ParserFixture : public Test
{
	public:
		ParserFixture() {}
		~ParserFixture() {}

		PeopleDataCollection people;
		std::stringstream fakeFile;
		Parser parser;

		void addPersonToFile(std::string name, int birthYear, int deathYear)
		{
			fakeFile << name << "," << birthYear << "," << deathYear << std::endl;
		}
};

TEST_F(ParserFixture, CreatesPeopleDataFromSingleLineOfData)
{
	addPersonToFile(name1, birthYear1, deathYear1);

	people = parser.parse(fakeFile);

	ASSERT_THAT(people.size(), Eq(1));
	EXPECT_THAT(people.at(0).name, StrEq(name1));
	EXPECT_THAT(people.at(0).birthYear, Eq(birthYear1));
	EXPECT_THAT(people.at(0).deathYear, Eq(deathYear1));
}

TEST_F(ParserFixture, CreatesPeopleDataFromMultipleLinesOfData)
{
	addPersonToFile(name1, birthYear1, deathYear1);
	addPersonToFile(name2, birthYear2, deathYear2);
	addPersonToFile(name3, birthYear3, deathYear3);

	people = parser.parse(fakeFile);

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
