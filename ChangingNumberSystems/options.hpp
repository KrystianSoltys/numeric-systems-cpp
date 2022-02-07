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

const std::string DEFAULT_TR_FILENAME = "translation.txt";


class Translation
{
public:
	Translation(const std::string& = DEFAULT_TR_FILENAME);
	virtual ~Translation() {};

	const std::string& Read() const;

private:
	std::string filename {};
	std::vector<std::vector<std::string>> translations {};
	std::vector<std::string> lang_versions {};

	bool readFile();

};


#endif //OPTIONS_HPP