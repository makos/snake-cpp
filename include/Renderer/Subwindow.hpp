#pragma once
#include <curses.h>
#include <memory>
#include <string>
#include "Renderer.hpp"
#include "Util/Point.hpp"
// #include "Window.hpp"
#include "IWindow.hpp"
// class Window;

class Subwindow : public IWindow {
   public:
    Subwindow(IWindow *win, int height, int width, int posy, int posx);

    void print(int y, int x, std::string msg) override;
    void print(int y, int x, std::string msg, Color color) override;
    void print(int y, int x, std::string msg, chtype attr) override;
    void print(Point pos, std::string msg) override;
    void print(Point pos, std::string msg, Color color) override;
    void print(Point pos, std::string msg, chtype attr) override;

    void setBox(bool state) override;
    int setDelay(bool state) override;
    int setKeypad(bool state) override;
    int refresh() override;
    int erase() override;
    int clear() override;
    int getKey() override;

    Point size() override;

    WINDOW *get() override;

   private:
    std::unique_ptr<WINDOW> mWindow;
    bool mBox;
};