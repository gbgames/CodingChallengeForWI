#ifndef GB_EVENT_EXTRACTOR_H
#define GB_EVENT_EXTRACTOR_H

#include "ImportantEvent.h"
#include "PeopleData.h"

class EventExtractor
{
	public:
		EventExtractor();
		~EventExtractor();
	
		ImportantEvents convert(const PeopleDataCollection & people); 
};

#endif
