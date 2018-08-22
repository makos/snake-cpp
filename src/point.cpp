#include "point.hpp"
#include <iostream>

Point::Point() : y(0), x(0) {}

Point::Point(int y, int x) : y(y), x(x) {}

Point::Point(const Point &other) : y(other.y), x(other.x) {}

bool Point::operator==(const Point &other) const {
    return (other.y == this->y && other.x == this->x);
}

bool Point::operator!=(const Point &other) const { return !(*this == other); }