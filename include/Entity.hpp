/*
 * Entity.hpp - interface class for dynamic game objects to inherit from.
 */
#pragma once

class Point;

class IEntity {
  public:
    virtual ~IEntity() = default;
    virtual Point &getPosition() = 0;
};