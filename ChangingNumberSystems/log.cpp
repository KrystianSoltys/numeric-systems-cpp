#include "log.hpp"

Log::Log(const std::string& filePath)
	: filename(filePath)
{
	std::ofstream file;
	file.open(filename, std::ios_base::app);

	if (!file.is_open())
	{
		throw BadLogFile("Problem with log file occured.");
	}

	file << getDate() << "   " << std::left << std::setw(13) <<
		"Note: " << DEFAULT_WELCOME_MESS << std::endl;

	file.close();
}

void Log::SetFilename(const std::string & filePath)
{
	if (filePath == this->filename) return;

	AddToLog("Log file changed -> " + filePath);
	filename = filePath;
}

const std::string & Log::Path() const noexcept
{
	return filename;
}

void Log::AddToLog(const std::string & data, bool isExc) const
{
	std::ofstream file;
	file.open(filename, std::ios_base::app);

	if (!file.is_open())
	{
		throw BadLogFile("Problem with log file occured.");
	}

	file << getDate() << "   " << std::left << std::setw(13) << 
		((isExc) ? "Exception: " : "Note: " ) <<
		data << std::endl;

	
	file.close();
}

std::string Log::getDate() const
{
	using std::to_string;

	std::string day = "", month = "", year = "", hour = "", min = "", sec="";

	time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm l;
	localtime_s(&l, &t);

	if (l.tm_mday < 10) day = "0";
	day += to_string(l.tm_mday);

	if (l.tm_mon < 10) month = "0";
	month += to_string(l.tm_mon+1);

	year = to_string(l.tm_year + 1900);

	if (l.tm_hour < 10) hour = "0";
	hour += to_string(l.tm_hour);

	if (l.tm_min < 10) min = "0";
	min += to_string(l.tm_min);

	if (l.tm_sec < 10) sec = "0";
	sec += to_string(l.tm_sec);


	return std::string("[" + day + "." + month + "." + year +
						" | " + hour + ":" + min + ":" + sec + "]");
}
