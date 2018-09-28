#include "Application.h"

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

void Application::avviati() 
{
	while (true) {
		switch (menu()) {
		case 1:
			fill();
			break;
		case 2:
			print();
			break;
		case 3:
			switch (sub_menu())
			{
			case 1:
				mediaAritmetica();
				break;
			case 2:
				mediaArmonica();
				break;
			case 3:
				mediaAritmeticaPonderata();
				break;
			case 4:
				mediaGeometrica();
				break;
			default:
				break;
			}
			break;
		case 4:
			varianza();
			break;
		case 5:
			mediaAritmetica();
			mediaAritmeticaPonderata();
			mediaArmonica();
			mediaGeometrica();
			varianza();
			riepilogo();
			break;
		case 6:
			riepilogo();
			break;
		case 7:
			return;
		default:
			break;
		}
		system("pause");
	}
}

//Display the menu
int Application::menu()
{
	system("cls");
	std::cout << "- MENU -" << std::endl;
	std::cout << "1) CARICA DATI" << std::endl;
	std::cout << "2) STAMPA DATI" << std::endl;
	std::cout << "3) CALCOLA MEDIA" << std::endl;
	std::cout << "4) CALCOLA VARIANZA" << std::endl;
	std::cout << "5) CALCOLA TUTTO" << std::endl;
	std::cout << "6) RIEPILOGO" << std::endl;
	std::cout << "7) ESCI" << std::endl;


	int scelta = 0;
	std::cin >> scelta;

	return scelta;

}

//Display the sub menu
int Application::sub_menu()
{
	system("cls");
	std::cout << "- CALCOLA MEDIA -" << std::endl;
	std::cout << "1) MEDIA ARITMETICA" << std::endl;
	std::cout << "2) MEDIA ARMONICA" << std::endl;
	std::cout << "3) MEDIA ARITMETICA PONDERATA" << std::endl;
	std::cout << "4) MEDIA GEOMETRICA" << std::endl;
	std::cout << "5) INDIETRO" << std::endl;


	int scelta = 0;
	std::cin >> scelta;
	
	return scelta;
}

//fill the vector
void Application::fill() 
{
	reset();
	system("cls");
	int size = 0;
	std::cout << "numeri da inserire: ";
	std::cin >> size;
	std::cout << std::endl;
	float temp = 0;
	for (int i = 0; i < size; i++) {
		printf("\n%i) Inserisci un numero: ", i + 1);
		std::cin >> temp;
		vec.push_back(temp);
	}
	std::sort(vec.begin(), vec.end(), [](int a, int b) {return a < b; });
}


void Application::mediaAritmetica() 
{
	system("cls");
	if (m_mediaAritmetica) return;
	float s = 0;
	int n = vec.size();
	for (int i = 0; i < n; i++)	s += vec.at(i) / n;


	m_mediaAritmetica = s;

	printf("Media Aritmetica: %.3f\n", m_mediaAritmetica);
}

void Application::mediaArmonica() 
{
	system("cls");
	if (m_mediaArmonica) return;

	float s = 0;
	int n = vec.size();
	for (int i = 0; i < n; i++)	s += 1 / vec.at(i);


	m_mediaArmonica = n / s;

	printf("Media Armonica: %.3f\n", m_mediaArmonica);
}
void Application::mediaAritmeticaPonderata() 
{
	system("cls");
	if (m_mediaAritmeticaPonderata) return;

	float s = 0;
	int n = vec.size();
	for (int i = 0; i < n; i++)	s += vec.at(i);


	m_mediaAritmeticaPonderata = s / n;


	printf("Media Aritmetica Ponderata: %.3f\n", m_mediaAritmeticaPonderata);
}
void Application::mediaGeometrica()
{
	system("cls");
	if (m_mediaGeometrica) return;
	if (vec.size() == 0) return;

	int n = vec.size();
	float m = vec.at(1);
	for (int i = 1; i < n - 1; i++)	m *= vec.at(i + 1);

	m_mediaGeometrica = powf(m, 1 / (float)n);


	printf("Media Geometrica: %.3f\n", m_mediaGeometrica);
}
void Application::varianza() 
{
	system("cls");
	if (m_varianza)	return;
	if(!m_mediaAritmetica)	mediaAritmetica();

	float s2 = 0;
	int n = vec.size();

	for (int i = 0; i < n; i++) s2 += powf((vec.at(i) - m_mediaAritmetica), 2);
	s2 = s2 / ((float)n - 1);
	m_varianza = powf(s2, 1 / (float)2);
	
	printf("Varianza: %.3f\n", m_varianza);
}

void Application::reset()
{
	system("cls");
	vec.erase(vec.begin(), vec.end());
	m_mediaAritmetica = 0;
	m_mediaAritmeticaPonderata = 0;
	m_mediaArmonica = 0;
	m_mediaGeometrica = 0;
	m_varianza = 0;
}

void Application::print()
{
	system("cls");
	for (const float& num : vec)
	{
		printf("%.2f\n",num);
	}
}

void Application::riepilogo()
{
	system("cls");
	std::cout << "- RIEPILOGO -" << std::endl;
	std::cout << "( 0 se il valore non e' stato calcolato )" << std::endl;
	printf("Media Aritmetica: %.2f\n", m_mediaAritmetica);
	printf("Media Aritmetica Ponderata: %.2f\n", m_mediaAritmeticaPonderata);
	printf("Media Armonica: %.2f\n", m_mediaArmonica);
	printf("Media Geometrica: %.2f\n", m_mediaGeometrica);
	printf("Varianza: %.2f\n", m_varianza);
}
