#ifndef GB_DATE_VALIDATOR_H
#define GB_DATE_VALIDATOR_H

struct  PeopleData;

class DateValidator
{
	public:
		DateValidator(int startYear, int endYear);
		~DateValidator();

		bool validate(PeopleData & person) const;
};

#endif
