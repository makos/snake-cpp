/*
 * Entity.hpp - interface class for dynamic game objects to inherit from.
 */
#pragma once

class Point;

class IEntity {
  public:
    // virtual void draw(const Point &pos) = 0;
    virtual void move(const Point &dir) = 0;
    virtual Point &getPosition() = 0;
    // virtual char getChar() = 0;
};