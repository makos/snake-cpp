/*
 * Callback.hpp - callback functions to be used by MenuItems in a Menu.
 */
#pragma once
class Game;

namespace Callback {

void continueClicked(Game &game);
void newClicked(Game &game);
void exitClicked(Game &game);

} // namespace Callback