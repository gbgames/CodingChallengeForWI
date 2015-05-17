#include "MaxLivesFinder.h"
#include <algorithm>

using namespace EVENT;

MaxLivesFinder::MaxLivesFinder()
{
}

MaxLivesFinder::~MaxLivesFinder()
{
}

MaxLivesResult MaxLivesFinder::searchEvents(const ImportantEvents & events)
{
	MaxLivesResult result;
	MaxLivesResult currentLives;
	for (ImportantEvents::const_iterator iter = events.begin(); iter != events.end(); ++iter)
	{
		if (iter->eventType == BIRTH_EVENT)
		{
			currentLives.earliestYear = iter->year;
			currentLives.idCollection.push_back(iter->id);
			if (result.idCollection.size() < currentLives.idCollection.size())
			{
				result = currentLives;
			}
		}
		else if (iter->eventType == DEATH_EVENT)
		{
			currentLives.idCollection.erase(std::remove(currentLives.idCollection.begin(), currentLives.idCollection.end(), iter->id));
		}
	}

	return result;
}
