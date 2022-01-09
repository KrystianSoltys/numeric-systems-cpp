#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <fstream>
#include "ui.hpp"

static const std::string DEFAULT_LOG_FILENAME = "log.txt";

class Log
{
public:
	Log(const std::string& filePath = DEFAULT_LOG_FILENAME);
	virtual ~Log() = default;

	bool SetFilename(const std::string& filePath);
	const std::string& Path() const noexcept;
	
	bool AddToLog(const std::string& data) const;
	bool AddToLog(const char* data) const;


protected:
	std::string filename;

};



#endif // !LOG_HPP

