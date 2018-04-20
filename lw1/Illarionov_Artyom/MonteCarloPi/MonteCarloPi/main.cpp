#include "stdafx.h"
#include "MonteCarlo.h"

static const std::string HELP_OPTION = "--help";
static const size_t MIN_THREADS = 1;
static const size_t MIN_ITERATIONS = 1;

void Help()
{
	std::cout << "Use: MonteCarloPi.exe <iterations>\n"
		<< "Enter: \"MonteCarloPi.exe --help\" for help" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		if (argc == 2 && argv[1] == HELP_OPTION)
		{
			Help();
		}
		else
		{
			std::cout << ">Invalid count of arguments!" << std::endl;
			Help();	
		}
		return 1;
	}

	size_t iterations = atoi(argv[1]);
	size_t threads = atoi(argv[2]);

	if (iterations < MIN_ITERATIONS || threads < MIN_THREADS)
	{
		std::cout << "The number of iterations or threads must be greater than zero!" << std::endl;
		return 1;
	}

	MonteCarlo monteCarlo(iterations, threads);

	clock_t start = clock();
	std::cout << monteCarlo.CalculatePi() << std::endl;
	clock_t end = clock();

	float runtime = (float)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Runtime: " << runtime << std::endl;

	system("pause");
	return 0;
}