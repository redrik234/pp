#include "Random.h"

Point Random::GeneratePoint(const size_t squareSide)
{
	return Point(GenerateDouble(squareSide), GenerateDouble(squareSide));
}

double Random::GenerateDouble(const size_t squareSide)
{
	return (double)(rand()) / RAND_MAX * squareSide - squareSide / 2;
}
