#include "SimpleYearReporter.h"

#include "MaxLivesResult.h"
#include "gmock/gmock-matchers.h"

using namespace ::testing;

TEST(SimpleYearReporter, OutputsYearFromResults)
{
	MaxLivesResult result;
	result.earliestYear = 1990;

	SimpleYearReporter reporter;

	EXPECT_THAT(reporter.report(result), StrEq("Year with most living people at once: 1990"));
}
