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

Application::Application()
{	
	//directory del file testuale contenenti i valori da caricare
	std::string path = "data.txt";

	//caricamento del vettore con i dati presi dal file testuale
	loadFromFile(path);	

	// numero totale elementi
	for (const value& val : vec) n += val.frequency; 
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
	//std::sort(vec.begin(), vec.end(), [](int a, int b) {return a < b; });
}


void Application::mediaAritmetica() 
{
	system("cls");
	if (m_mediaAritmetica) return;
	long double s = 0;
	size_t k = vec.size();
	for (int i = 0; i < k; i++) {

		long double xi = vec.at(i).number;
		int			ni = vec.at(i).frequency;
		s += (xi * ni) / n;
	}

	m_mediaAritmetica = s;

	printf("Media Aritmetica: %.3f\n", m_mediaAritmetica);
}

void Application::mediaArmonica() 
{
	system("cls");
	if (m_mediaArmonica) return;

	long double s = 0;
	size_t k = vec.size();
	for (int i = 0; i < k; i++) {

		long double xi = vec.at(i).number;
		int			ni = vec.at(i).frequency;
		s += ni / xi;
	}


	m_mediaArmonica = n / s;

	printf("Media Armonica: %.3f\n", m_mediaArmonica);
}
void Application::mediaAritmeticaPonderata()
{
	system("cls");
	if (m_mediaAritmeticaPonderata) return;

	long double s = 0;
	size_t k = vec.size();
	long long int pesoTot = 0;
	long double numTot = 0;
	for (int i = 0; i < k; i++) {

		int wi = vec.at(i).weight;
		int ni = vec.at(i).frequency;
		pesoTot += wi * ni;
	}

	for (int i = 0; i < k; i++) {

		long double xi = vec.at(i).number;
		int ni = vec.at(i).frequency;
		int wi = vec.at(i).weight;
		numTot += wi * ni * xi;
	}


	m_mediaAritmeticaPonderata = numTot / pesoTot;


	printf("Media Aritmetica Ponderata: %.3f\n", m_mediaAritmeticaPonderata);
}
void Application::mediaGeometrica()
{
	system("cls");
	if (m_mediaGeometrica) return;
	if (vec.size() == 0) return;

	size_t k = vec.size();
	long double m = powl(vec.at(0).number, vec.at(0).frequency);
	for (int i = 0; i < k - 1; i++)
	{
		long double xi = vec.at(i + 1).number;
		int			ni = vec.at(i + 1).frequency;

		m *= powl(xi, ni);
	}

	m_mediaGeometrica = powl(m, 1 / (long double)n );


	printf("Media Geometrica: %.3f\n", m_mediaGeometrica);
}
void Application::varianza() 
{
	system("cls");
	if (m_varianza)	return;
	if(!m_mediaAritmetica)	mediaAritmetica();

	long double s2 = 0;

	//for (int i = 0; i < n; i++) s2 += powl((vec.at(i).number - m_mediaAritmetica), 2);
	//s2 = s2 / ((long double)n - 1);
	//m_varianza = powl(s2, 1 / (long double)2);
	m_varianza = 0; 
	
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
	printf("Valore\tPeso\tFrequenza\n");
	for (const value& val : vec)
	{
		printf("%.2f\t%i\t%i\n", val.number, val.weight, val.frequency);
	}
}

void Application::riepilogo()
{
	system("cls");
	std::cout << "- RIEPILOGO -" << std::endl;
	//std::cout << "( 0 se il valore non e' stato calcolato )" << std::endl;
	printf("Media Aritmetica: %.2f\n", m_mediaAritmetica);
	printf("Media Aritmetica Ponderata: %.2f\n", m_mediaAritmeticaPonderata);
	printf("Media Armonica: %.2f\n", m_mediaArmonica);
	printf("Media Geometrica: %.2f\n", m_mediaGeometrica);
	printf("Varianza: %.2f\n", m_varianza);
}

Application::value::value(long double number, int weight, int frequency)
	:
	number(number),
	weight(weight),
	frequency(frequency)
{}

void Application::loadFromFile(std::string& path)
{
	std::cout << "Initializing reading sequence" << std::endl;
	std::ifstream input(path);
	
	std::string line;
	while (std::getline(input, line, ','))
	{
		parse(line);
	}

	

	input.close();

	std::sort(vec.begin(), vec.end(), [](const value& a, const value& b) {return a.number < b.number; });
	system("pause");
}

void Application::parse(std::string& line)
{
	std::string number, weight, frequency;

	line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end()); //get rid of all the spaces

	number = getNumberfromString(line);

	weight = trimByDelim(':', line);
	if (weight == "nis") weight = "100";

	frequency = trimByDelim('*', line);
	if (frequency == "nif")	frequency = "1";


	addToVec(number, weight, frequency);
}

std::string Application::trimByDelim(const char& delim, std::string& line) 
{
	size_t start = line.find(delim);
	if (start == std::string::npos) return "nis";//not in string
	int len = 0;

	for (size_t i = start + 1; i < line.length(); i++, len++)
	{
		const char& c = line.at(i);
		if ( c == ':' || c == '*')
			break;
	}

	return line.substr(start + 1, len);
	
}

std::string Application::getNumberfromString(std::string& line)
{
	int start = 0, len = 1;
	for (const char& c : line)
	{
		if (c == '.' || (c >= '0' && c <= '9')) break;
		start++;
	}
	for (int i = start + 1; i < line.length(); i++, len++)
	{
		const char& c = line.at(i);
		if ( c == ':' || c == '*')	break;
	}

	return line.substr(start, len);
}

void Application::addToVec(std::string& number, std::string& weight, std::string& frequency)
{
	long double n = std::stold(number);
	int w = std::stoi(weight);
	int f = std::stoi(frequency);

	vec.push_back(value(n, w, f));
}