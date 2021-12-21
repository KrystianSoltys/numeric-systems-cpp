#include "ui.hpp"

using std::cout;
using std::cin;
using std::endl;


void ui::Headline()
{
	cout << "--------- Number Systems Calculator " << VERSION << " ---------\n\n";
}

uint ui::SelectNumeric()
{
	uint n;
	cout << "Provide numeric system (2 - 16): ";
	cin >> n;
	return n;
}

uint ui::FilePart()
{
	return uint();
}
