#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <string>
#include <exception>
typedef unsigned int uint;

static uint MAX_NUMERIC_SYS = 16;


namespace ui
{
	static std::string VERSION = "v0.1";
	void Headline();
	uint MainMenu();
	uint SelectNumeric();
	uint FilePart();
	uint ManualPart();
}


class Numeric_exc : public std::ex

#endif // !UI_HPP

