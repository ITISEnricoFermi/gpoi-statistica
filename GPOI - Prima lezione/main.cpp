#include "Application.h"

int main(int argc, char** argv) 
{
	if (argc == 1) {
		info();
		system("pause");
		exit(EXIT_FAILURE);
	}

	std::string path;
	if (argc == 2)	path = argv[1];	
	Application* programma = new Application(path);

	programma->avviati();
	delete programma;

	return 0;
}

