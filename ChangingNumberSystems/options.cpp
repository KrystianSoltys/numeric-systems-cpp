#include "options.hpp"

bool Options::parseFile()
{
	std::ifstream file;
	file.open(filename, std::ios_base::in);

	if (!file) return false;

	std::string option{};
	std::string value{};
	std::string line{};

	while (std::getline(file, line))
	{
		if (line[0] == '#') continue; // # is commenting

		std::istringstream is(line);
		std::getline(is, option, ':');
		std::getline(is, value);

		mapSettings.insert(PairStr(option, value));
	}

	file.close();
	return true;
}

Options::Options(const std::string& optFN, const std::string& trFN)
	: filename(optFN)
{
	translationObj = Translation(trFN);
	parseFile();

	uint i = 0;
	while (mapSettings.at("LANG") != translationObj.lang_versions[i]
			&& i < translationObj.lang_versions.size())
		i++;

	if(translationObj.lang_versions[i] != mapSettings.at("LANG")) i=0;

	languageInt = i;
}

const std::vector<std::string>& Options::GetLangVersions() const noexcept
{
	return translationObj.lang_versions;
}

const std::string& Options::GetTranslation(uint line) const
{
	return translationObj.GetTranslation(line, languageInt);
}

Translation::Translation(const std::string& fn) : filename(fn)
{
	parseFile();
}

const std::string&
Translation::GetTranslation(uint line, uint lang) const
{
	if (lang > lang_versions.size())
		lang = 0;

	if (line > translations.size())
		line = 0;

	return translations.at(line).at(lang);
}

bool Translation::parseFile()
{
	std::ifstream file;
	file.open(filename, std::ios_base::in);
	
	//if (!file) return false;
	

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
		std::istringstream stringStream(line);
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