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
//print info about the program usage
void info()
{
	std::cout << std::endl << "pass the path to file containing data as a parameter!" << std::endl << std::endl
		<< "The file should be structured as follows separated by a comma" << std::endl
		<< " ------------------------------------------" << std::endl
		<< "|\tNUMBER : WEIGHT * FREQUENCY ,\t   |" << std::endl
		<< " ------------------------------------------" << std::endl
		<< "example( 104.2:100*4, ... )" << std::endl
		<< "Number: 104.2\tweight: 100%\tfrequency: 4 times" << std::endl << std::endl;
}
//custom value constructor
Application::value::value(long double number, int weight, int frequency)
	:
	number(number),
	weight(weight),
	frequency(frequency)
{}

//application constructor
Application::Application(std::string path)
{
	//directory del file testuale contenenti i valori da caricare
	//std::string path = "data.txt";

	//caricamento del vettore con i dati presi dal file testuale
	loadFromFile(path);

	// numero totale elementi
	for (const value& val : vec) n += val.frequency;
}

//run the application
void Application::avviati() 
{
	while (true) {
		switch (menu()) {
		case 1:
			print();
			break;
		case 2:
			switch (sub_menu()){
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
				continue;
				break;
			}
			break;
		case 3:
			varianza();
			break;
		case 4:
			mediaAritmetica();
			mediaAritmeticaPonderata();
			mediaArmonica();
			mediaGeometrica();
			varianza();
			riepilogo();
			break;
		case 5:
			riepilogo();
			break;
		case 6:
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
	std::cout << "1) STAMPA DATI" << std::endl;
	std::cout << "2) CALCOLA MEDIA" << std::endl;
	std::cout << "3) CALCOLA VARIANZA" << std::endl;
	std::cout << "4) CALCOLA TUTTO" << std::endl;
	std::cout << "5) RIEPILOGO" << std::endl;
	std::cout << "6) ESCI" << std::endl;


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
//calculate arithmetical average
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
//calculate armonical average
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
//calculate weighted arithmetical average
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
//calculate geometrical average
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
//calculate variance
void Application::varianza() 
{
	system("cls");
	if (m_varianza)	return;
	if(!m_mediaAritmetica)	mediaAritmetica();

	long double s2 = 0;
	size_t k = vec.size();
	for (size_t i = 0; i < k; i++)
	{
		long double xi = vec.at(i).number;
		int ni = vec.at(i).frequency;
		s2 = ni * pow(xi - m_mediaAritmetica, 2);
	}
	m_varianzaQ = s2;
	//for (int i = 0; i < n; i++) s2 += powl((vec.at(i).number - m_mediaAritmetica), 2);
	//s2 = s2 / ((long double)n - 1);
	//m_varianza = powl(s2, 1 / (long double)2);
	m_varianza = sqrtl(m_varianzaQ); 
	
	printf("Varianza^(2): %.3f\nVarianza: %.3f\n", m_varianzaQ, m_varianza);
}
//print the content of the vector
void Application::print()
{
	system("cls");
	printf("Valore\tPeso\tFrequenza\n");
	for (const value& val : vec)
	{
		printf("%.2f\t%i\t%i\n", val.number, val.weight, val.frequency);
	}
}
//print the current status of all the calculations
void Application::riepilogo()
{
	system("cls");
	std::cout << "- RIEPILOGO -" << std::endl;
	//std::cout << "( 0 se il valore non e' stato calcolato )" << std::endl;
	printf("Media Aritmetica: %.2f\n", m_mediaAritmetica);
	printf("Media Aritmetica Ponderata: %.2f\n", m_mediaAritmeticaPonderata);
	printf("Media Armonica: %.2f\n", m_mediaArmonica);
	printf("Media Geometrica: %.2f\n", m_mediaGeometrica);
	printf("Varianza^(2): %.2f\n", m_varianzaQ);
	printf("Varianza: %.2f\n", m_varianza);
}
//load file to get data from
void Application::loadFromFile(std::string& path)
{
	std::ifstream input(path);
	if (!input.is_open()) {
		std::cout << path << std::endl;
		std::cout << "Si e' verificato un errore durante l'apertura del file!\nControlla che il percorso sia corretto!" << std::endl;
		exit(EXIT_FAILURE);
		return;
	}
	std::string line;
	while (std::getline(input, line, ','))
	{
		parse(line);
	}

	

	input.close();

	std::sort(vec.begin(), vec.end(), [](const value& a, const value& b) {return a.number < b.number; });
}
//function for parsing data from file
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
//extract the number followed by a specific delimiter
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
//searches for 'number' inside the string
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
//Converts from string and add the elements to the vector
void Application::addToVec(std::string& number, std::string& weight, std::string& frequency)
{
	long double n = std::stold(number);
	int w = std::stoi(weight);
	int f = std::stoi(frequency);

	vec.push_back(value(n, w, f));
}