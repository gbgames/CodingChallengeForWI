#ifndef GB_SIMPLE_YEAR_REPORTER_H
#define GB_SIMPLE_YEAR_REPORTER_H

#include <string>

class MaxLivesResult; 

class SimpleYearReporter
{
	public:
		SimpleYearReporter();
		~SimpleYearReporter();

		std::string report(const MaxLivesResult & result) const;
};

#endif
