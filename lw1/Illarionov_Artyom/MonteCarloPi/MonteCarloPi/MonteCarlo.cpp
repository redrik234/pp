#include "stdafx.h"
#include "MonteCarlo.h"
#include <random>
#include "Point.h"

MonteCarlo::MonteCarlo(size_t iterations)
	:m_iterations(iterations)
{
}

double MonteCarlo::CalculatePi()
{
	size_t pointsInCircle = 0;
	for (size_t i = 0; i < m_iterations; ++i)
	{
		Point point((double)(rand()) / RAND_MAX * SQUARE_SIDE - SQUARE_SIDE / 2, 
					(double)(rand()) / RAND_MAX * SQUARE_SIDE - SQUARE_SIDE / 2);

		if (pow(point.GetX(), 2) + pow(point.GetY(), 2) <= R)
		{
			++pointsInCircle;
		}
	}

	return COEFF * (double)pointsInCircle / (double)m_iterations;
}