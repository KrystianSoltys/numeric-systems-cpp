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


class Options
{
public:
	Options(const std::string& fn);
	virtual ~Options() {};

	const std::string& Read() const;

private:
	std::string filename {};
	std::vector<std::vector<std::string>> lang_text {};
	std::vector<std::string> lang_versions {};

};


#endif //OPTIONS_HPP