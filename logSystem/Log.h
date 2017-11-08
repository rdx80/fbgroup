/* Log.h

Copyright (c) 2017 by Andreas Gustafsson (rdx80@icloud.com)

"LogSystem" is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

"LogSystem" is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

*/
#ifndef RDX80_LOG_H
#define RDX80_LOG_H

#include <string>
#include <fstream>

enum LogType {
	INFO,
	WARNING,
	CRITICAL
};

class Log
{
public:
	Log();
	~Log();

	void Add(LogType logType, std::string message);

private:
	std::ofstream file_;
	std::string filePath_;


	void startLog();
	std::string getTime();
	std::string getDate();
	std::string getTimeStamp();
};

#endif // RDX80_LOG_H