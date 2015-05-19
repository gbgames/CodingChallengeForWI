#ifndef GB_IDATE_VALIDATOR_H
#define GB_IDATE_VALIDATOR_H

struct PeopleData;

class IDateValidator
{
	public:
		virtual ~IDateValidator() {}

		virtual bool validate(PeopleData & person) const = 0;
};

#endif
