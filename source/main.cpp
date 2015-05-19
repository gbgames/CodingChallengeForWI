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

#include "Parser.h"
#include "DateValidator.h"
#include "EventExtractor.h"
#include "MaxLivesFinder.h"
#include "PeopleReporter.h"
#include "SimpleYearReporter.h"

#include <fstream>
#include <iostream>

enum ReportType
{
	SIMPLE_REPORT,
	DETAILED_REPORT
};

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: CodingChallengeForWI [FILE] <SIMPLE|DETAILED>" << std::endl;
	}
	else
	{
		ReportType reportType = SIMPLE_REPORT;
		if (argc == 3)
		{
			if (std::string(argv[2]) == "DETAILED")
			{
				reportType = DETAILED_REPORT;
			}
		}

		std::ifstream fileInput(argv[1]);
		if (!fileInput)
		{
			std::cout << "File " << argv[1] << " cannot be opened. Does it exist?" << std::endl;
		}

		//TODO: Range specified by user.
		DateValidator validator(1900, 2000);
		PeopleDataCollection collection = Parser().parse(fileInput, validator);

		if (!collection.empty())
		{
			ImportantEvents events = EventExtractor().convert(collection);

			MaxLivesResult result = MaxLivesFinder().searchEvents(events);

			//TODO: Create factory to create a reporter based on user input:
			//IReporter * reporter = reporterFactory.create(argv[2], collection);
			IReporter * reporter(0); 
			if (SIMPLE_REPORT == reportType)
			{
				reporter = new SimpleYearReporter();
			}
			else if (DETAILED_REPORT == reportType)
			{
				reporter = new PeopleReporter(collection);
			}

			std::cout << reporter->report(result) << std::endl;
			delete reporter;
		}
		else
		{
			std::cout << "No entries found when parsing." << std::endl;
		}
	}

	return 0;
}
