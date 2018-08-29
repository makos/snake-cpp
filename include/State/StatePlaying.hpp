/*
 * StatePlaying.hpp - where the actions takes place. Game rendering, player
 * movement, scoring etc. happen here.
 */
#pragma once
#include <memory>
#include "Entities/Apple.hpp"
#include "Entities/Player.hpp"
#include "Renderer/Window.hpp"
#include "State.hpp"
class Game;

class StatePlaying : public IState {
   public:
    StatePlaying(Game &game);
    ~StatePlaying();

    void update() override;
    void input() override;
    void render(Renderer &renderer) override;

    bool canMove();

   private:
    Game &mGame;
    std::unique_ptr<Window> mWindow;
    std::unique_ptr<Window> mScoreWindow;
    Player mPlayer;
    std::unique_ptr<Apple> mApple;
};