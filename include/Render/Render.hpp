/*
 * Render.hpp - wrapper over ncurses. Lots of work to do here still.
 */
#pragma once
#include <curses.h>
#include <string>

enum Color { Black, Red, Green, Yellow, Blue, Magenta, Cyan, White };

class Render {
  public:
    Render();
    ~Render();

    void print(WINDOW *win, int y, int x, std::string msg);
    void print(WINDOW *win, int y, int x, std::string msg, Color color);
    void print(int y, int x, std::string msg);
    void print(int y, int x, std::string msg, Color color);
    void print(int y, int x, std::string msg, chtype attr);
    void print(WINDOW *win, int y, int x, std::string msg, chtype attr);

  private:
};