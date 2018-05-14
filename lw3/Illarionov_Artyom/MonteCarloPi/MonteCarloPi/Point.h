#pragma once

class Point
{
public:
	Point(double x, double y);

	double GetX() const;
	double GetY() const;

private:
	double m_x = 0;
	double m_y = 0;
};