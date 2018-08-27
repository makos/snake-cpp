/*
 * Renderer.hpp - high(er) level wrapper over ncurses.
 * Provides methods that don't work on any particular Window, but rather on
 * stdscr which is ncurses' pointer to the whole available screen area.
 */
#pragma once
#include <curses.h>
#include <string>
#include "Util/Point.hpp"
class Window;

enum Color { Black, Red, Green, Yellow, Blue, Magenta, Cyan, White };

class Renderer {
   public:
    Renderer();
    ~Renderer();

    void sleep(int ms);

    void print(int y, int x, std::string msg);
    void print(int y, int x, std::string msg, Color color);
    void print(int y, int x, std::string msg, chtype attr);

    void print(Point pos, std::string msg);
    void print(Point pos, std::string msg, Color color);
    void print(Point pos, std::string msg, chtype attr);

    void clearAll();
    void eraseAll();
    void refreshAll();

    void setDelay(bool state);
};