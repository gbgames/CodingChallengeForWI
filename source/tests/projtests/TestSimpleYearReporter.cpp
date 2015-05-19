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
