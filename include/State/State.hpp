/*
 * State.hpp - interface class for other states to inherit from.
 */
#pragma once
class Render;

class IState {
  public:
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render(Render &render) = 0;
};