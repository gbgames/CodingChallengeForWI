#include "Parser.h"
#include "DateValidator.h"
#include "EventExtractor.h"
#include "MaxLivesFinder.h"
#include "SimpleYearReporter.h"

#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: CodingChallengeForWI [FILE]" << std::endl;
	}
	else
	{
		std::ifstream fileInput(argv[1]);
		if (fileInput)
		{
			//TODO: Range specified by user.
			DateValidator validator(1900, 2000);
			PeopleDataCollection collection = Parser().parse(fileInput, validator);

			if (!collection.empty())
			{
				ImportantEvents events = EventExtractor().convert(collection);

				MaxLivesResult result = MaxLivesFinder().searchEvents(events);

				//TODO: Create factory to create a reporter based on user input:
				//SIMPLE - just the year
				//DETAILED - year and names of people
				//IReporter reporter = reporterFactory.create(argv[2], collection);
				std::cout << SimpleYearReporter().report(result) << std::endl;
			}
			else
			{
				std::cout << "No entries found when parsing." << std::endl;
			}
		}
		else
		{
			std::cout << "File " << argv[1] << " cannot be opened. Does it exist?" << std::endl;
		}
	}

	return 0;
}
