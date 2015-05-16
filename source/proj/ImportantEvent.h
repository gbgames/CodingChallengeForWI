#ifndef GB_IMPORTANT_EVENT_H
#define GB_IMPORTANT_EVENT_H

#include "EventType.h"
#include "PersonID.h"

struct ImportantEvent
{
	ImportantEvent(int year_, EVENT::Type eventType_, PersonID identifier_);
	~ImportantEvent();

	bool operator<(const ImportantEvent & rhs) const;

	int year;
	EVENT::Type eventType;
	PersonID id;
};

#endif
