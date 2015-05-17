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
	ImportantEvents sortedEvents = events;
	std::sort(sortedEvents.begin(), sortedEvents.end());
	MaxLivesResult result;
	MaxLivesResult currentLives;
	for (ImportantEvents::const_iterator iter = sortedEvents.begin(); iter != sortedEvents.end(); ++iter)
	{
		if (iter->eventType == BIRTH_EVENT)
		{
			handleBirthEvent(result, currentLives, *iter);
		}
		else if (iter->eventType == DEATH_EVENT)
		{
			handleDeathEvent(currentLives, *iter);
		}
	}

	return result;
}

void MaxLivesFinder::handleBirthEvent(MaxLivesResult & result, MaxLivesResult & currentLives, const ImportantEvent & event)
{
	currentLives.earliestYear = event.year;
	currentLives.idCollection.push_back(event.id);
	if (result.idCollection.size() < currentLives.idCollection.size())
	{
		result = currentLives;
	}
}

void MaxLivesFinder::handleDeathEvent(MaxLivesResult & currentLives, const ImportantEvent & event)
{
	currentLives.idCollection.erase(std::remove(currentLives.idCollection.begin(), currentLives.idCollection.end(), event.id));
}
