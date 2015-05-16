#include "MaxLivesFinder.h"

MaxLivesFinder::MaxLivesFinder()
{
}

MaxLivesFinder::~MaxLivesFinder()
{
}

MaxLivesResult MaxLivesFinder::searchEvents(const ImportantEvents & events)
{
	MaxLivesResult result;
	result.earliestYear = events.at(0).year;
	result.idCollection.push_back(events.at(0).id);

	return result;
}
