#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <string>
typedef unsigned int uint;

namespace ui
{
	static std::string VERSION = "v0.1";
	void Headline();
	uint MainMenu();
	uint SelectNumeric();
	uint FilePart();
	uint ManualPart();
}

#endif // !UI_HPP

