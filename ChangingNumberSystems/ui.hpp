#ifndef UI_HPP
#define UI_HPP

#include "options.hpp"
#include "calculator.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>


typedef unsigned int uint;

inline void cls();

namespace ui
{
	static std::string VERSION = "v0.1";

	void Headline() noexcept;
	uint MainMenu();			//throws out_of_range
	uint SelectNumeric();		//throws out_of_range
	uint FilePart();
	std::string ManualPart();
}



#endif // !UI_HPP

