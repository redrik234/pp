#pragma once

static const size_t SQUARE_SIDE = 2;
static const size_t R = 1;
static const double COEFF = 4.0;

class MonteCarlo
{
public:
	MonteCarlo(size_t iterations);
	double CalculatePi();

private:
	size_t m_iterations;
	size_t pointsInCircle;
};