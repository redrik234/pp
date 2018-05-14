#include "stdafx.h"
#include "MonteCarlo.h"

static const std::string HELP_OPTION = "--help";
static const std::size_t MIN_ITERATIONS = 1;

void Help()
{
	std::cout << "Use: MonteCarloPi.exe <iterations>\n"
		<< "Enter: \"MonteCarloPi.exe --help\" for help" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << ">Invalid count of arguments!" << std::endl;
		Help();
		return EXIT_FAILURE;
	}

	if (argv[1] == HELP_OPTION)
	{
		Help();
		return EXIT_SUCCESS;
	}

	size_t iterations = atoi(argv[1]);

	if (iterations < MIN_ITERATIONS)
	{
		std::cout << "The number of iterations must be greater than zero!" << std::endl;
		return EXIT_FAILURE;
	}

	MonteCarlo monteCarlo(iterations);

	return 0;
}