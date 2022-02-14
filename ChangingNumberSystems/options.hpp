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
	void SetLanguageInt(int) noexcept;

private:
	std::string filename{};

	Translation translationObj{};
	std::map<std::string, std::string> mapSettings{};

	uint languageInt{};

	bool parseFile();
};

const std::string DEFAULT_OPTIONS_CONTENT =
"LANG:EN";

const std::string DEFAULT_TRANSLATION_CONTENT =
"EN;PL\n\
Error;Blad\n\
Press any key to continue;Nacisnij dowolny klawisz aby kontynuowac\n\
Numeric Systems Calculator;Kalkulator Systemow Liczbowych\n\
Manual calculator;Tryb manualny\n\
File source calculator;Tryb odczytu z pliku\n\
Options;Opcje\n\
About&Help;Autor i pomoc\n\
Exit;Wyjscie\n\
Choose module;Wybierz modul\n\
Provide numeric system;Podaj system liczbowy\n\
Provide file path;Podaj sciezke do pliku\n\
Enter number;Podaj numer\n\
From base;Z systemu\n\
To base;Do systemu\n\
Source;Zrodlo\n\
Result;Wynik\n\
Created by;Autor\n\
README file avaivle on GitHub page;Plik README dostepny na stronie GitHub projektu\n\
See you again!;Do zobaczenia!\n\
Incorrect module number.;Niepoprawny numer modulu.\n\
Provided numeric system out of range!;Podany system liczbowy jest poza zakresem!\n\
Provided module number does not exists!;Podany modul nie istnieje!\n\
File can not be opened!;Nie mozna otworzyc pliku!\n\
To few lines in file!;Plik jest zbyt krotki!\n\
File can not be opened during writing data!;Plik nie moze zostac otwarty do zapisu danych!\n\
Select option; Wybierz ustawienie\n\
Language; Jezyk\n\
Exit; Wyjscie\n\
Choose application language; Wybierz jezyk aplikacji\n\
Choice; Twoj wybor\n\
Incorrect language provided, try again; Wybrano nieprawidlowy jezyk, sprobuj ponownie";

#endif //OPTIONS_HPP