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
