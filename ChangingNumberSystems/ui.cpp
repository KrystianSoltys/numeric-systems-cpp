#include "ui.hpp"

using std::cout; using std::cin; using std::endl;

inline void cls()
{
	system("cls");
	ui::Headline();
}


void ui::Headline() noexcept
{
	cout << "--------- Number Systems Calculator " << VERSION << " ---------\n\n";
}

uint ui::MainMenu(std::string& msg)
{
	cls();

    if(msg!="")
    {
        cout << msg << endl;
        //cout << "Check log.txt file for more information." << endl << endl;
		cout << endl;
		msg = "";
    }
	cout << "[1] Manual calculator.\n";
	cout << "[2] File source calculator.\n";
	cout << "[3] Options\n";
	cout << "[4] About&Help\n\n";
	cout << "[0] Exit\n\n";
	cout << "Choose module: ";
	uint n;
	cin >> n;

	if (n > 4) throw std::out_of_range("Provided module number does not exists!");
	cls();
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

void ui::FilePart()
{
	std::string path;
	cout << "Provide file path: ";
	cin >> path;

	std::fstream file;
	file.open(path, std::ios::in);

	if (!file.is_open())
		throw BadFile("File can not be opened!");

	uint srcBase, destBase;
	std::vector<std::string> nums; //string due to possible letters in nums
	std::string x;

	while (file >> x) //reading from file
		nums.push_back(x);

	file.close();


	if (nums.size() < 3)
	{
		file.close();
		throw BadDataInFile("To few lines in file!");
	}

	srcBase = std::stoi(nums.at(nums.size() - 2));
	destBase = std::stoi(nums.at(nums.size() - 1));

	if (srcBase < 2 || srcBase > MAX_NUMERIC_SYS ||
		destBase < 2 || destBase > MAX_NUMERIC_SYS)
	{
		throw std::out_of_range("Provided numeric system in file out of range!");
	}

	nums.resize(nums.size() - 2);

	std::vector<Calc> calculations;

	for (auto& i : nums)
		calculations.push_back(Calc(srcBase, destBase, i));

	file.open(path, std::ios::app);
	if (!file.is_open())
	{
		throw BadFile("File can not be opened during writing data!");
	}

	file << "\n\n";
	for (auto& i : calculations) //writing to file
	{
		file << i.Result() << endl;
	}

	file.close();

}

void ui::ManualPart()
{
	uint srcBase, destBase;
	std::string srcNum;
	cout << "Enter number: ";
	cin >> srcNum;

	cls();

	cout << "From base:\n";
	srcBase = SelectNumeric();

	cls();

	cout << "To base:\n";
	destBase = SelectNumeric();

	Calc obl(srcBase, destBase, srcNum);

    cls();

    cout << "Source: " << srcNum << " (" << srcBase << ")\n\n";
    cout << "Result: " << obl.Result() << " (" << destBase << ")\n\n";
	system("pause");
}

void ui::About() noexcept
{
    cls();
    cout << "Created by Intelek\n";
    cout << "README file available on GitHub page" << endl;
	system("pause");
}
