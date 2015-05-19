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
