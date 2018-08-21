#pragma once

class Point {
  public:
    Point();
    Point(int y, int x);
    Point(const Point &other);
    bool operator==(const Point &other);

  public:
    int y;
    int x;
};