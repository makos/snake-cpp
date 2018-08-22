#pragma once

class Point {
  public:
    Point();
    Point(int y, int x);
    Point(const Point &other);
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

  public:
    int y;
    int x;
};