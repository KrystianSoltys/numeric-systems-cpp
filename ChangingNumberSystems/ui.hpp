#ifndef UI_HPP
#define UI_HPP

#include "options.hpp"
#include "calculator.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>
#include <fstream>
#include <algorithm>


inline void cls();
inline bool IntsOnlyInStr(const std::string&);

namespace ui
{
	static std::string VERSION = "in Dev";

	void Headline() noexcept;
	uint MainMenu(std::string& msg);    //throws out_of_range
	uint SelectNumeric();		        //throws out_of_range
	void FilePart();			        //throws multiple exc
	void ManualPart();			        //throws multiple exc
	void About() noexcept;
}

//exception class for file problems
class BadFile : public std::exception
{
public:
	BadFile(const char* message = "Problem with file occured!") :
        msg_(message) {}
	virtual const char* what() const noexcept
	{
		return msg_.c_str();
	}

protected:
    std::string msg_;
};

class BadDataInFile : public std::exception
{
public:
	BadDataInFile(const char* message = "Problem with file occured!") :
		msg_(message) {}
	virtual const char* what() const noexcept
	{
		return msg_.c_str();
	}

protected:
    std::string msg_;
};
#endif // !UI_HPP

