#include "options.hpp"

Translation::Translation(const std::string& fn) : filename(fn)
{
	readFile();
}

bool Translation::readFile()
{
	std::ifstream file;
	file.open(filename, std::ios_base::in);

	//if (!file.is_open()) return false;

	std::string line{};
	std::string val{};
	std::vector<std::string> tempVec{};

	std::getline(file, line);
	std::istringstream stringStreamFirst(line);
	while (std::getline(stringStreamFirst, val, ';'))
	{
		tempVec.push_back(val);
	}
	lang_versions = tempVec;
	tempVec.clear();

	while (std::getline(file, line))
	{
		std::istringstream stringStream (line);
		while (std::getline(stringStream, val, ';'))
		{
			tempVec.push_back(val);
		}
		if (tempVec.size() != lang_versions.size()) return false;
		translations.push_back(tempVec);
		tempVec.clear();
	}

	file.close();
	return true;
}