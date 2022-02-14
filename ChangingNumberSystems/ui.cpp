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
	cout << "\n" << GetString(1) << ".." << endl;
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
	cout << GetString(1) << endl;
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
	cout << "--------- " << GetString(2) << " " << VERSION << " ---------\n\n";
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
	cout << "[1] " << GetString(3) << ".\n";
	cout << "[2] " << GetString(4) << ".\n";
	cout << "[3] " << GetString(5) << "\n";
	cout << "[4] " << GetString(6) << "\n\n";
	cout << "[0] " << GetString(7) << "\n\n";
	cout << GetString(8) << ": ";
	uint n;
	cin >> n;

	if (n > 4) throw std::out_of_range(GetString(21));
	cls();
	return n;
}

uint UI::SelectNumeric()
{
	uint n;
	cout  << GetString(9) << " (2 - " << MAX_NUMERIC_SYS << "): ";
	cin >> n;
	if (n < 2 || n > MAX_NUMERIC_SYS) throw std::out_of_range(GetString(20));

	return n;
}

void UI::FilePart()
{
	std::string path;
	cout << GetString(10) << ": ";
	cin >> path;

	std::fstream file;
	file.open(path, std::ios::in);

	if (!file.is_open())
		throw BadFile(GetString(22).c_str());

	uint srcBase, destBase;
	std::vector<std::string> nums; //string due to possible letters in nums
	std::string x;

	while (file >> x) //reading from file
		nums.push_back(x);

	file.close();


	if (nums.size() < 3)
	{
		file.close();
		throw BadDataInFile(GetString(23).c_str());
	}

	srcBase = std::stoi(nums.at(nums.size() - 2));
	destBase = std::stoi(nums.at(nums.size() - 1));

	if (srcBase < 2 || srcBase > MAX_NUMERIC_SYS ||
		destBase < 2 || destBase > MAX_NUMERIC_SYS)
	{
		throw std::out_of_range(GetString(20));
	}

	nums.resize(nums.size() - 2);

	std::vector<Calc> calculations;

	for (auto& i : nums)
		calculations.push_back(Calc(srcBase, destBase, i));

	file.open(path, std::ios::app);
	if (!file.is_open())
	{
		throw BadFile(GetString(24).c_str());
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
	cout << GetString(11) << ": ";
	cin >> srcNum;

	cls();

	cout << GetString(12) << ":\n";
	srcBase = SelectNumeric();

	cls();

	cout << GetString(13) << ":\n";
	destBase = SelectNumeric();

	Calc obl(srcBase, destBase, srcNum);

	cls();

	cout << GetString(14) << ": " << srcNum << " (" << srcBase << ")\n\n";
	cout << GetString(15) << ": " << obl.Result() << " (" << destBase << ")\n\n";
	Wait();
}

void UI::OptionsMenu()
{
	uint choice = 1;
	while (choice == 1)
	{
		cls();
		cout << GetString(25) << ":\n\n";
		cout << "[1] " << GetString(26) << "\n";
		cout << "\n[0] " << GetString(27) << "\n\n";
		cout << GetString(29) << ": ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cls();
			uint selectedLang;
			cout << GetString(28) << ": \n\n";
			for (uint i = 0; i < optObj->GetLangVersions().size(); i++)
			{
				cout << "[" << i + 1 << "] " << optObj->GetLangVersions().at(i) << endl;
			}
			cout << "\n" << GetString(29) << ": ";
			cin >> selectedLang;
			if (selectedLang > optObj->GetLangVersions().size() || !selectedLang)
			{
				cls();
				cout << GetString(30) << "\n\n";
				Wait();
				break;
			}
			else
			{
				optObj->SetLanguageInt(selectedLang-1);
				break;
			}
		default:
			break;
		}
	}
	
} 

void UI::About() noexcept
{
	cls();
	cout << GetString(16) << ": Intelek\n";
	cout << GetString(17) << endl;
	Wait();
}

const std::string& UI::GetString(uint x) const noexcept
{
	return optObj->GetTranslation(x);
}
