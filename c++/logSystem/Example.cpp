/* Example.cpp

Copyright (c) 2017 by Andreas Gustafsson (rdx80@icloud.com)

"LogSystem" is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

"LogSystem" is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

*/
#include "Log.h"

int main()
{
	Log log;	// Create an instance of the Log object

	// Add a entry to the log file.
	log.Add(INFO, "A info entry to the log.");

	log.Add(WARNING, "A Warning entry to the log.");

	log.Add(CRITICAL, "A critical entry to the log.");

	return 0;
}

