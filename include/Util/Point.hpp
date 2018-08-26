/*
 * Point.hpp - 2D (y,x) point class.
 * Note that it is (y,x) and not (x,y), because ncurses handles it the same way.
 */
#pragma once

class Point {
  public:
    Point();
    Point(int y, int x);
    Point operator+(const Point &other);
    Point &operator+=(const Point &other);
    Point operator-(const Point &other);
    Point &operator-=(const Point &other);
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

  public:
    int y;
    int x;
};