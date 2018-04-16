#pragma once
#include <Windows.h>

static const size_t R = 1;
static const size_t SQUARE_SIDE = 2;
static const double COEFF = 4.0;
static const size_t MIN_THREAD_COUNT = 1;

class MonteCarlo
{
public:
	MonteCarlo() = default;
	MonteCarlo(size_t iterations);

private:
	size_t m_iterations;
};