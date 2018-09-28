#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>
//#include <cstdlib> //may be usefull on certain compilers

class Application
{
	/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	/*
	-MENU-
	1) CARICA DATI
	2) CALCOLA MEDIA
	3) CALCOLA VARIANZA
	4) ESCI
	*/

	/*
	-SUB MENU-
	~ CALCOLA MEDIA
		1) MEDIA ARITMETICA
		2) MEDIA ARMONICA
		3) MEDIA ARITMETICA PONDERATA
		4) MEDIA GEOMETRICA
		5) INDIETRO

	*/

//PUBLIC STUFF
public:
	void avviati();
	Application();
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
