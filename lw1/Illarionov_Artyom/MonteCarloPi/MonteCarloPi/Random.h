#pragma once
#include "Point.h"

class Random
{
public:
	static Point GeneratePoint(const size_t squareSide);

private:
	static double GenerateDouble(const size_t squareSide);
};