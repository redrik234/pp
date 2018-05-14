#include "MonteCarlo.h"
#include "Point.h"
#include "Random.h"
#include <Windows.h>
#include <omp.h>

MonteCarlo::MonteCarlo(size_t iterations)
	:m_iterations(iterations)
{
	pointsInCircle = 0;
}

size_t MonteCarlo::pointsInCircle = 0;

double MonteCarlo::CalculatePi()
{
	Random random;
	
	#pragma omp parallel for
	for (int i = 0; i < m_iterations; ++i)
	{
		Point point = random.GeneratePoint(SQUARE_SIDE);

		if (pow(point.GetX(), 2) + pow(point.GetY(), 2) <= R)
		{
			InterlockedIncrement(&pointsInCircle);
		}
	}

	return COEFF * (double)pointsInCircle / (double)m_iterations;
}
