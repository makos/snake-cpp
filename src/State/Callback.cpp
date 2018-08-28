#include "State/Callback.hpp"
#include "Game.hpp"
#include "State/StatePlaying.hpp"

namespace Callback {

void newClicked(Game &game) {
    game.clearStates();
    game.renderer().clearAll();
    game.renderer().refreshAll();
    game.pushState(std::make_unique<StatePlaying>(game));
}

void exitClicked(Game &game) { game.setRunning(false); }

void continueClicked(Game &game) { game.popState(); }

void settingsClicked(Game &game) {}

}  // namespace Callback