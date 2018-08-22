/*
 * main.cpp - ncurses, game structures etc. initialization and hand-off.
 * This should be detached from the actual logic as much as possible.
 */
#include "Game.hpp"

int main(int argc, char *argv[]) {
    Game game;
    game.run();
    return 0;
}