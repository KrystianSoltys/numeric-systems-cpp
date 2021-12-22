#ifndef CALCULATOR_HPP
#define	CALCULATOR_HPP

typedef unsigned long long ull;
typedef unsigned int uint;

class Calc
{
public:
	Calc(uint sb, uint db, ull sn);

private:
	void Convert();

private:
	uint srcBase{};
	uint destBase{};
	ull srcNum{};

	ull result{};

};




#endif // !CALCULATOR_HPP

