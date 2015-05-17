#ifndef GB_MAX_LIVES_FINDER_H
#define GB_MAX_LIVES_FINDER_H

#include "ImportantEvent.h"
#include "MaxLivesResult.h"

class MaxLivesFinder
{ 
	public:
		MaxLivesFinder();
		~MaxLivesFinder();

		MaxLivesResult searchEvents(const ImportantEvents & events);
	
	private:
		void handleBirthEvent(MaxLivesResult & result, MaxLivesResult & currentLives, const ImportantEvent & event);
		void handleDeathEvent(MaxLivesResult & currentLives, const ImportantEvent & event);
};

#endif
