/*
 * Renderer.hpp - wrapper over ncurses. Lots of work to do here still.
 */
#pragma once
#include <curses.h>
#include <string>
class Window;

enum Color { Black, Red, Green, Yellow, Blue, Magenta, Cyan, White };

class Renderer {
  public:
    Renderer();
    ~Renderer();

    void sleep(int ms);

    void print(Window &win, int y, int x, std::string msg);
    void print(Window &win, int y, int x, std::string msg, Color color);
    void print(int y, int x, std::string msg);
    void print(int y, int x, std::string msg, Color color);
    void print(int y, int x, std::string msg, chtype attr);
    void print(Window &win, int y, int x, std::string msg, chtype attr);

    void clearAll();
    void eraseAll();
    void refreshAll();

    void setDelay(bool state);
};