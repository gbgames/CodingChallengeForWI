#ifndef GB_DATE_VALIDATOR_MOCK_H
#define GB_DATE_VALIDATOR_MOCK_H

#include "IDateValidator.h"

#include "PeopleData.h"
#include <gmock/gmock.h>

class DateValidatorMock : public IDateValidator
{
	public:
		DateValidatorMock();
		virtual ~DateValidatorMock();

		MOCK_CONST_METHOD1(validate, bool (PeopleData & person));
};
#endif
