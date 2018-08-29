#include "Util/Point.hpp"

Point::Point() : y(0), x(0) {}

Point::Point(int y, int x) : y(y), x(x) {}

Point Point::operator+(const Point &other) {
    Point tmp(*this);
    tmp.y += other.y;
    tmp.x += other.x;
    return tmp;
}

Point &Point::operator+=(const Point &other) {
    this->y += other.y;
    this->x += other.x;
    return *this;
}

Point Point::operator-(const Point &other) {
    Point tmp(*this);
    tmp.y -= other.y;
    tmp.x -= other.x;
    return tmp;
}

Point &Point::operator-=(const Point &other) {
    this->y -= other.y;
    this->x -= other.x;
    return *this;
}

bool Point::operator==(const Point &other) const {
    return (other.y == this->y && other.x == this->x);
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.y << "," << point.x << ")";
    return out;
}

bool Point::operator!=(const Point &other) const { return !(*this == other); }

Point Point::randomPoint(std::minstd_rand &rng, int miny, int maxy, int minx,
                         int maxx) {
    std::uniform_int_distribution<int> uniY(miny, maxy);
    std::uniform_int_distribution<int> uniX(minx, maxx);

    return Point(uniY(rng), uniX(rng));
}