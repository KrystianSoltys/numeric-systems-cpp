#include "ui.hpp"

using std::cout; using std::cin; using std::endl;

void cls()
{
	system("cls");
	ui::Headline();
}

void ui::Headline()
{
	cout << "--------- Number Systems Calculator " << VERSION << " ---------\n\n";
}

uint ui::MainMenu()
{
	ui::Headline();
	
	cout << "[1] Manual calculator.\n";
	cout << "[2] File source calculator.\n";
	cout << "[3] Options\n";
	cout << "[4] About&Help\n\n";
	cout << "[0] Exit\n\n";
	cout << "Choose module: ";
	uint n;
	cin >> n;

	if (n > 4) throw std::out_of_range("Provided modeule number does not exists!");

	return n;
}

uint ui::SelectNumeric()
{
	uint n;
	cout << "Provide numeric system (2 - " << MAX_NUMERIC_SYS << "): ";
	cin >> n;
	if (n < 2 || n > MAX_NUMERIC_SYS) throw std::out_of_range("Provided numeric system out of range!");

	return n;
}

uint ui::FilePart()
{
	return uint();
}

void ui::ManualPart()
{
	unsigned long long srcNum, srcBase, destBase;
	cout << "Enter number: ";
	cin >> srcNum;
	
	cls();

	cout << "From base:\n";
	srcBase = SelectNumeric();

	cls();

	cout << "To base:\n";
	destBase = SelectNumeric();

}
