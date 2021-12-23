#ifndef UI_HPP
#define UI_HPP

#include "options.hpp"
#include "calculator.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>
#include <fstream>

typedef unsigned int uint;

inline void cls();
inline bool IntsOnlyInStr(const std::string&);

namespace ui
{
	static std::string VERSION = "v0.1";

	void Headline() noexcept;
	uint MainMenu();			//throws out_of_range
	uint SelectNumeric();		//throws out_of_range
	void FilePart();			//throws 
	void ManualPart();			//throws
	void About() noexcept;
}

//exception class for file problems
class BadFile : public std::exception
{
public:
	BadFile(const char* message = "Problem with file occured!") :
		std::exception(message) {}
	virtual const char* what() const noexcept 
	{
		return std::exception::what();
	}
};

class BadDataInFile : public std::exception
{
public:
	BadDataInFile(const char* message = "Problem with file occured!") :
		std::exception(message) {}
	virtual const char* what() const noexcept
	{
		return std::exception::what();
	}
};
#endif // !UI_HPP

