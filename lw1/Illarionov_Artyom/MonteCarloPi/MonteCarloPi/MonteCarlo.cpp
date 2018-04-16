#include "stdafx.h"
#include "MonteCarlo.h"
#include <random>

MonteCarlo::MonteCarlo(size_t iterations)
	:m_iterations(iterations)
{
}

double MonteCarlo::CalculatePi()
{
	size_t pointsInCircle = 0;
	for (size_t i = 0; i < m_iterations; ++i)
	{
		double x = (double)(rand()) / RAND_MAX * SQUARE_SIDE - SQUARE_SIDE / 2;
		double y = (double)(rand()) / RAND_MAX * SQUARE_SIDE - SQUARE_SIDE / 2;

		if (pow(x, 2) + pow(y, 2) <= R)
		{
			++pointsInCircle;
		}
	}

	return COEFF * (double)pointsInCircle / (double)m_iterations;
}