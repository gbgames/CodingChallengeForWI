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

#include "PeopleReporter.h"

#include "MaxLivesResult.h"
#include <sstream>

PeopleReporter::PeopleReporter(const PeopleDataCollection & people) : 
	m_people(people)
{
}

PeopleReporter::~PeopleReporter()
{
}

std::string PeopleReporter::report(const MaxLivesResult & result) const
{
	std::stringstream reportOutput;
	reportOutput << "Year with most living people at once: " << result.earliestYear;

	for (PersonIDCollection::const_iterator iter = result.idCollection.begin(); iter != result.idCollection.end(); ++iter)
	{
		reportOutput << std::endl << getNameById(*iter);
	}

	return reportOutput.str();
}

std::string PeopleReporter::getNameById(PersonID id) const
{
	bool foundPerson(false);
	std::string name;
	for (PeopleDataCollection::const_iterator iter = m_people.begin(); iter != m_people.end() && !foundPerson; ++iter)
	{
		if (iter->id == id)
		{
			foundPerson = true;
			name = iter->name;
		}
	}

	return name;
}
