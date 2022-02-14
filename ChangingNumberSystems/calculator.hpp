#ifndef CALCULATOR_HPP
#define	CALCULATOR_HPP

#include <string>
#include <cmath>
#include <algorithm>

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

using ull = unsigned long long;
using uint = unsigned int;

static uint MAX_NUMERIC_SYS = 16;

ull xPow(uint a, uint b = 2);
char IntToChar(uint x);

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

class CalculationExc : public std::exception
{
public:
	CalculationExc(const char* message = "Cannot be calculated!") :
		msg_(message) {}
	virtual const char* what() const noexcept
	{
		return msg_.c_str();
	}

protected:
	std::string msg_;
};


#endif // !CALCULATOR_HPP

