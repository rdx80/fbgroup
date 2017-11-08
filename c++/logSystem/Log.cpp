/* Log.cpp

Copyright (c) 2017 by Andreas Gustafsson (rdx80@icloud.com)

"LogSystem" is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

"LogSystem" is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

*/
#include <iostream>
#include <time.h>
#include <windows.h>

#include "Log.h"
#include "const.h"

Log::Log()
{
	if(DEBUGLOG)	// Sets true/false in "const.h"
	startLog();
}


Log::~Log()
{
	// Close the log file.
	if(DEBUGLOG)
	file_.close();
}

void Log::startLog()
{
	// Create "Log" directory if it dosn´t exist!
	CreateDirectory("log", nullptr);

	// Create the filePath
	filePath_ = "log\\" + getTimeStamp();

	for (int i = 0; i<filePath_.length(); ++i)
	{
		if (filePath_[i] == '/' || filePath_[i] == ':')
			filePath_[i] = '-';
	}

	filePath_.append(".txt");


	file_.open(filePath_.c_str());
	if (file_.fail())
		perror(filePath_.c_str());

}

std::string Log::getTime()
{
	char stime[9];
	_strtime_s(stime);
	return stime;
}

std::string Log::getDate()
{
	char sdate[9];
	_strdate_s(sdate);
	return sdate;
}

std::string Log::getTimeStamp()
{
	return getDate() + " - " + getTime();
}

void Log::Add(LogType logType, std::string message)
{
	std::string type;
	if (logType == LogType::INFO)
		type = "\"INFO\"\t - ";

	if (logType == LogType::WARNING)
		type = "\"WARNING\"\t - ";

	if (logType == LogType::CRITICAL)
		type = "\"CRITICAL\" - ";

	if(DEBUGLOG)
	file_ << getTimeStamp() << " - " << type << message << "\n"; 

}