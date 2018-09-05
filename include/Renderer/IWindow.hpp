#pragma once
#include <string>
#include "Renderer.hpp"
#include "Util/Point.hpp"

class IWindow {
   public:
    virtual ~IWindow() = default;

    virtual void print(int y, int x, std::string msg) = 0;
    virtual void print(int y, int x, std::string msg, Color color) = 0;
    virtual void print(int y, int x, std::string msg, chtype attr) = 0;
    virtual void print(Point pos, std::string msg) = 0;
    virtual void print(Point pos, std::string msg, Color color) = 0;
    virtual void print(Point pos, std::string msg, chtype attr) = 0;

    virtual void setBox(bool state) = 0;
    virtual int setDelay(bool state) = 0;
    virtual int setKeypad(bool state) = 0;
    virtual int refresh() = 0;
    virtual int erase() = 0;
    virtual int clear() = 0;
    virtual int getKey() = 0;

    virtual Point size() = 0;
    virtual Point position() = 0;

    virtual WINDOW* get() = 0;
};