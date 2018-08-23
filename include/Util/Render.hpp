/*
 * Render.hpp - wrapper over ncurses. Lots of work to do here still.
 */
#pragma once
#include <curses.h>
#include <string>

enum Color { Red = 1, Green, Yellow };

class Render {
  public:
    Render(int height, int width);
    ~Render();

    int kpad(bool state);
    int kpad(WINDOW *win, bool state);
    void setBox(bool state);

    void print(WINDOW *win, int y, int x, std::string msg);
    void print(WINDOW *win, int y, int x, std::string msg, Color color);
    void print(int y, int x, std::string msg);
    void print(int y, int x, std::string msg, Color color);

    void update();
    void clear();

    int getKey();

  private:
    WINDOW *mGameboard;
    bool drawBox;
};