#ifndef GB_DATE_VALIDATOR_H
#define GB_DATE_VALIDATOR_H

#include "IDateValidator.h"

class DateValidator : public IDateValidator
{
	public:
		DateValidator(int startYear, int endYear);
		virtual ~DateValidator();

		virtual bool validate(PeopleData & person) const;
	
	private:
		int m_beginRange;
		int m_endRange;
};

#endif
