/*
 * State.hpp - interface class for other states to inherit from.
 */
#pragma once
class Renderer;

class IState {
  public:
    virtual ~IState() = default;
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render(Renderer &renderer) = 0;
};