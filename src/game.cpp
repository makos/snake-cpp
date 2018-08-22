#include "Game.hpp"

Game::Game() : screen(20, 20), mScore(0), mIsRunning(true) {}

Game::~Game() {}

// Main loop
void Game::run() {}

bool Game::isRunning() { return mIsRunning; }

void Game::setRunning(bool state) { mIsRunning = state; }