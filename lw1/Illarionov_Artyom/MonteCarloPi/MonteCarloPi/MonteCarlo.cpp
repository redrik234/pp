#include "stdafx.h"
#include "MonteCarlo.h"
#include "Random.h"
#include "Point.h"

MonteCarlo::MonteCarlo(size_t iterations)
	:m_iterations(iterations)
{
}

double MonteCarlo::CalculatePi()
{
	Random random;
	size_t pointsInCircle = 0;
	for (size_t i = 0; i < m_iterations; ++i)
	{
		Point point = random.GeneratePoint(SQUARE_SIDE);

		if (pow(point.GetX(), 2) + pow(point.GetY(), 2) <= R)
		{
			++pointsInCircle;
		}
	}

	return COEFF * (double)pointsInCircle / (double)m_iterations;
}