#ifndef OPTIONS_HPP
#define OPTIONS_HPP

/*
Example of translation.txt
//
EN;PL;ES
Hello;Czesc;Hola
It's an example;To jest przyklad;Esto es un ejemplo 
//
*/

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using uint = std::uint32_t;
using PairStr = std::pair<std::string, std::string>;

const std::string DEFAULT_OPT_FILENAME = "options.txt";
const std::string DEFAULT_TR_FILENAME = "translation.txt";

class Options;

class Translation
{
public:
	Translation(const std::string & = DEFAULT_TR_FILENAME);
	virtual ~Translation() {};

	const std::string& GetTranslation(uint, uint) const;

private:
	std::string filename{};
	std::vector<std::vector<std::string>> translations{};
	std::vector<std::string> lang_versions{};

	bool parseFile();

	friend class Options;
};

class Options
{
public:
	Options(const std::string & = DEFAULT_OPT_FILENAME,
			const std::string & = DEFAULT_TR_FILENAME);
	~Options() = default;

	const std::vector<std::string>& GetLangVersions() const noexcept;
	const std::string& GetTranslation(uint) const;
	

private:
	std::string filename{};

	Translation translationObj{};
	std::map<std::string, std::string> mapSettings{};

	uint languageInt{};

	bool parseFile();
};



#endif //OPTIONS_HPP