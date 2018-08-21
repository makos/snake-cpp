#include "point.hpp"

Point::Point()
{
    y = 0;
    x = 0;
}

Point::Point(int y, int x) : y(y), x(x) {}

Point::Point(const Point &other) : y(other.y), x(other.x) {}

bool Point::operator==(const Point &other)
{
    return other.y == y && other.x == x;
}
