#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>

static const std::string DEFAULT_LOG_FILENAME = "log.txt";
const std::string DEFAULT_WELCOME_MESS =
		"Program opened and ready to work.";
const std::string DEFAULT_GOODBYE_MESS =
		"Program closed propertly.";
const std::string DEFAULT_CRITICAL_MESS =
		"Program suddenly closed.";

class Log
{
public:
	Log(const std::string& filePath = DEFAULT_LOG_FILENAME);
	virtual ~Log() = default;

	void SetFilename(const std::string& filePath);
	const std::string& Path() const noexcept;
	
	void AddToLog(const std::string& data, bool isExc = false) const;


protected:
	std::string filename;

	std::string getDate() const;
};

class BadLogFile : public std::exception
{
public:
	BadLogFile(const char* message = "Problem with file occured!") :
		msg_(message) {}
	virtual const char* what() const noexcept
	{
		return msg_.c_str();
	}

protected:
	std::string msg_;
};

#endif // !LOG_HPP

