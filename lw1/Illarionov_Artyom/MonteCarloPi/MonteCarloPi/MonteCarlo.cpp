#include "stdafx.h"
#include "MonteCarlo.h"
#include "Random.h"
#include "Point.h"
#include "ThreadHandler.h"

MonteCarlo::MonteCarlo(size_t iterations, size_t threads)
	:m_iterations(iterations)
	,m_threads(threads)
{
}

size_t MonteCarlo::m_pointsInCircle = 0;

double MonteCarlo::CalculatePi()
{
	if (m_threads == MIN_THREAD_COUNT)
	{
		CountPointInCircle(&m_iterations);
	}
	else
	{
		ThreadHandler handler;
		std::vector<size_t> iterVec(m_threads - 1, m_iterations / (m_threads - 1));
		iterVec.push_back(m_iterations % (m_threads - 1));
		for (size_t &iter : iterVec)
		{
			handler.CreateThrd(CountPointInCircle, &iter);
		}
		handler.JoinAll();
	}

	return COEFF * (double)m_pointsInCircle / (double)m_iterations;
}

DWORD WINAPI MonteCarlo::CountPointInCircle(LPVOID lParam)
{
	const size_t iterations = *(size_t*)lParam;

	Random rand;
	for (size_t i = 0; i < iterations; ++i)
	{
		Point point = rand.GeneratePoint(SQUARE_SIDE);
		if (pow(point.GetX(), 2) + pow(point.GetY(), 2) <= R)
		{
			InterlockedIncrement(&m_pointsInCircle);
		}
	}
	return 0;
}