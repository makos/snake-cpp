#pragma once
class Render;

class State {
  public:
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render(Render &render) = 0;
};