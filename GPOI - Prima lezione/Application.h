#pragma once
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

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
public:
	void avviati();
private:
	//FUNCTIONS
	int menu();
	int sub_menu();
	void fill();
	void mediaAritmetica();
	void mediaArmonica();
	void mediaAritmeticaPonderata();
	void mediaGeometrica();
	void varianza();
	void reset();
	void print();
	void riepilogo();

	//VARIABLES
	std::vector<float> vec;
	float m_mediaAritmetica = 0;
	float m_mediaAritmeticaPonderata = 0;
	float m_mediaArmonica = 0;
	float m_mediaGeometrica = 0;
	float m_varianza = 0;

};