#include "log.hpp"

Log::Log(const std::string& filePath)
	: filename(filePath)
{
	std::ofstream file;
	file.open(filename);

	if (!file.is_open())
	{
		throw BadFile("Problem with log file occured.");
	}

	file.close();
}