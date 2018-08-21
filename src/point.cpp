#include "point.hpp"

Point::Point() {
    y = 0;
    x = 0;
}

Point::Point(int y, int x) : y(y), x(x) {}

Point::Point(const Point &other) : y(other.y), x(other.x) {}

bool Point::operator==(const Point &other) {
    return other.y == y && other.x == x;
}

// int Point::sety(int y) { this->y = y; }

// int Point::setx(int x) { this->x = x; }

// int Point::gety() { return y; }

// int Point::getx() { return x; }