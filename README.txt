Coding challange for WI application: CodingChallengeForWI.
Copyright 2015 Gianfranco Berardi

http://www.gbgames.com/

Twitter: @GBGames

In a real project, many questions about what is really being requested would
occur, and the conversation would have driven the decisions to build in 
flexibility or not. 

At the risk of overengineering, this project can be seen as having three major
responsibilities.

It parses a specified dataset of people listed with their birth and death years,
finds the year between 1900 and 2000 in which most of them were alive at the 
same time, and then outputs a report.

It ignores invalid data, whether it is a malformed entry or it is outside the 
range of years. It even ignores people who died before they were born.

By default, it outputs a simple report which prints out the year only. The
user can specify a more detailed report.

What I would have liked to have added:
- an optional anonymizer, which modifies the output to print out IDs instead
of names.
- a logger, which can be used to output errors. Currently the parser ignores
invalid data without informing the user that there is something wrong on any
given line. Perhaps a command line argument to specify if it should be logged 
to a file or standard out/error?
- a factory for the reporter types.
- a more robust command line argument handler. Right now, it handles missing
arguments, bad files, and bad reporter types well, but it could stand to 
have a module created that would be responsible, keeping main.cpp cleaner.
- a way to allow the user to specify the date range that would be considered
valid. It's hardcoded to the years 1900 and 2000, which technically meets the 
requirements, but it could be that a future request might want an arbirary 
range. Some examples are finding a solution in a subset of those years or in a 
different range entirely.

Because the entire project is test-driven and constantly refactored each step 
of the way, it would be relatively trivial to add these and other features, 
depending on the needs of the imaginary customer.

