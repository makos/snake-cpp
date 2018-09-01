/*
 * Window.hpp - high level wrapper over ncurses' WINDOW struct, providing
 * encapsulation of WINDOW related methods (in plain ncurses usually denoted
 * by w- prefix).
 */
#pragma once
#include <curses.h>
#include <memory>
#include <string>
#include "IWindow.hpp"
#include "Renderer.hpp"
#include "Util/Point.hpp"

class Window : public IWindow {
   public:
    Window(int height, int width, int posy, int posx);

    WINDOW *get() override;

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

   private:
    std::unique_ptr<WINDOW> mWindow;
    bool mBox;
};