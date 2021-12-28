#include "calculator.hpp"


ull xPow(uint a, uint b)
{
	if (b == 0) return 1;
	if (b == 1) return a;

	ull pr{ a };
	for (uint i = 1; i < b; i++)
	{
		pr *= a;
	}
	return pr;
}

char IntToChar(uint x)
{
	if (x < 10) return (x + '0');
	else return (x + 55);
}

Calc::Calc(uint sb, uint db, std::string& sn):
	srcBase(sb), destBase(db), srcNum(sn)
{
	for (char& i : srcNum) //number string to upper
		toupper(i);

	Convert();
}

void Calc::Convert()
{
	ull sum{ 0 };
	char ch;
	uint num{ 1 }; //avoiding UB

	std::reverse(srcNum.begin(), srcNum.end());

	for (uint i =0; i < srcNum.size(); i++)
	{
		ch = srcNum[i];
		if (ch >= 48 && ch <= 57)		//0-9
			num = ch - '0';
		else if (ch >= 65 && ch <= 90)	//A-Z
			num = ch - 55;
		else
			throw CalculationExc("Character out of range!");

		if (num >= srcBase)
			throw CalculationExc("Number not in right base");
		
		num *= xPow(srcBase, i);
		sum += num;
	}
	std::reverse(srcNum.begin(), srcNum.end()); //reversing again

	//checking len of result number
	uint len = 0;

	while (sum >= xPow(destBase, len))
		++len;

	//converting sum -> result string
	std::string res (len, '0');
	for (uint i = len - 1; i >= 0; i--)
	{
		if (sum == 0) break;
		res[i] = IntToChar(sum / xPow(destBase, i));
		sum = sum % xPow(destBase, i);
	}
	std::reverse(res.begin(), res.end());

	result = res;
}
