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
