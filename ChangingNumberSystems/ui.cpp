#include "UI.hpp"

using std::cout; using std::cin; using std::endl;

#ifdef _WIN32
inline void UI::cls() noexcept
{
	system("cls");
	Headline();
}
inline void UI::Wait() noexcept
{
	cout << GetString(2) << endl;
	cin.ignore();
	cin.get();
}

#elif unix
inline void UI::cls() noexcept
{
	system("clear");
	Headline();
}
inline void UI::Wait(const std::string& text) noexcept
{
	cout << GetString(2) << endl;
	cin.ignore();
	cin.get();
}
#endif

UI::UI(const Options& opt)
{
	optObj = std::make_shared<Options>(opt);
}

void UI::Headline() noexcept
{
	cout << "--------- " << GetString(3) << " " << VERSION << " -------- - \n\n";
}

uint UI::MainMenu(std::string& msg)
{
	cls();
    if(msg!="")
    {
        cout << msg << endl;
        //cout << "Check log.txt file for more information." << endl << endl;
		cout << endl;
		msg = "";
    }
	cout << "[1] " << GetString(4) << ".\n";
	cout << "[2] " << GetString(5) << ".\n";
	cout << "[3] " << GetString(6) << "\n";
	cout << "[4] " << GetString(7) << "\n\n";
	cout << "[0] " << GetString(8) << "\n\n";
	cout << "Choose module: ";
	uint n;
	cin >> n;

	if (n > 4) throw std::out_of_range("Provided module number does not exists!");
	cls();
	return n;
}

uint UI::SelectNumeric()
{
	uint n;
	cout << "Provide numeric system (2 - " << MAX_NUMERIC_SYS << "): ";
	cin >> n;
	if (n < 2 || n > MAX_NUMERIC_SYS) throw std::out_of_range("Provided numeric system out of range!");

	return n;
}

void UI::FilePart()
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

void UI::ManualPart()
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
	Wait();
}

void UI::About() noexcept
{
    cls();
    cout << "Created by Intelek\n";
    cout << "README file available on GitHub page" << endl;
	Wait();
}

const std::string& UI::GetString(uint x) const noexcept
{
	return optObj->GetTranslation(x);
}
