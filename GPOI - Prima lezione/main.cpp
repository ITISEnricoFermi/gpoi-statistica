#include "Application.h"

int main(int argc, char** argv) 
{

	Application* programma = new Application;
	programma->avviati();
	delete programma;

	return 0;
}