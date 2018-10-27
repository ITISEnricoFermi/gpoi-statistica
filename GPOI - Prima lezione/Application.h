#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>

void info();

class Application
{
//PUBLIC STUFF
public:
	void avviati();
	Application(std::string path = "data.txt");
private:

	struct value
	{
		long double number;
		unsigned int weight = 100;
		unsigned int frequency = 1;

		value(long double number, int weight = 100, int frequency = 1);
	};

	//FUNCTIONS
	int menu();
	int sub_menu();
	void mediaAritmetica();
	void mediaArmonica();
	void mediaAritmeticaPonderata();
	void mediaGeometrica();
	void varianza();
	void print();
	void riepilogo();
	void loadFromFile(std::string& path);
	void parse(std::string& line);
	void addToVec(std::string& number, std::string& weight, std::string& frequency);
	std::string getNumberfromString(std::string& line);
	std::string trimByDelim(const char& delim, std::string& line);

	//VARIABLES
	std::vector<value> vec;
	long double m_mediaAritmetica = 0;
	long double m_mediaAritmeticaPonderata = 0;
	long double m_mediaArmonica = 0;
	long double m_mediaGeometrica = 0;
	long double m_varianzaQ = 0;
	long double m_varianza = 0;
	long int n = 0;

};
