#ifndef CALCULATOR_HPP
#define	CALCULATOR_HPP

#include <string>
#include <cmath>

/*
Example of source.txt file to calc:
//
13
5		- numbers separated by new line char ( '\n' )
1FE
7A		
16		- source base
2		- destination base
//
*/



typedef unsigned int uint;


static uint MAX_NUMERIC_SYS = 16;

class Calc
{
public:
	Calc(uint sb, uint db, std::string& sn);
	const std::string& Result() const noexcept { return result; }

private:
	void Convert();

private:
	uint srcBase{};
	uint destBase{};
	std::string srcNum{}; //string due to possible letters in nums

	std::string result{};

};




#endif // !CALCULATOR_HPP

