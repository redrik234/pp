#pragma once
#include "Point.h"
#include <random>

class Random
{
public:
	static Point GeneratePoint(const size_t squareSide);

private:
	static double GenerateDouble(const size_t squareSide);
};