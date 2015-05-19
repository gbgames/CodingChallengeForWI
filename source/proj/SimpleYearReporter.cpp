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
#include <sstream>

SimpleYearReporter::SimpleYearReporter()
{
}

SimpleYearReporter::~SimpleYearReporter()
{
}

std::string SimpleYearReporter::report(const MaxLivesResult & result) const
{
	std::stringstream reportOutput;
	reportOutput << "Year with most living people at once: " << result.earliestYear;

	return reportOutput.str();
}
