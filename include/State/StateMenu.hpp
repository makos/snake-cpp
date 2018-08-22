#pragma once
#include "State.hpp"
#include <memory>
class Game;
class Menu;

class StateMenu : public State {
  public:
    StateMenu(Game &game);
    ~StateMenu();

    void input() override;
    void update() override;
    void render(Render &render) override;

    void newClicked();
    void exitClicked();

  private:
    // Game *mGame;
    // Menu *mMenu;
    std::unique_ptr<Game> mGame;
    std::unique_ptr<Menu> mMenu;
    int mItemSelected;
};