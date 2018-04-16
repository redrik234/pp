#include  "Point.h"

Point::Point(double x, double y)
	:m_x(x)
	, m_y(y)
{
}

double Point::GetX() const
{
	return m_x;
}

double Point::GetY() const
{
	return m_y;
}