#pragma once
#include "Menu.hpp"
#include "State.hpp"
#include <memory>
class Game;
class Menu;

namespace Callback {

void newClicked(Game &game);
void exitClicked(Game &game);

} // namespace Callback

class StateMenu : public State {
  public:
    StateMenu(Game &game);

    void input() override;
    void update() override;
    void render(Render &render) override;

  private:
    Game &mGame;
    std::unique_ptr<Menu> mMenu;
    unsigned int mItemSelected;
};