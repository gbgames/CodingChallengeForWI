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
	for (ImportantEvents::const_iterator iter = events.begin(); iter != events.end(); ++iter)
	{
		result.earliestYear = iter->year;
		result.idCollection.push_back(iter->id);
	}

	return result;
}
