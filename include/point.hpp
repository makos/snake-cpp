#pragma once

class Point {
  public:
    Point();
    Point(int y, int x);
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

  public:
    int y;
    int x;
};