#include "Menu/Menu.hpp"
#include "Menu/MenuItem.hpp"
#include "catch.hpp"

class Game {
  public:
    Game() : mIsRunning(true) {}
    ~Game() {}

    bool isRunning() { return mIsRunning; }
    void setRunning(bool state) { mIsRunning = state; }

  private:
    bool mIsRunning;
};

void callback(Game &g) { g.setRunning(false); }

TEST_CASE("Menu.hpp tests", "[menu]") {
    Game mockGame;
    Menu testMenu(mockGame);

    SECTION("Testing addItem() and items()") {
        testMenu.addItem("Test", callback);
        REQUIRE(testMenu.items()[0]->text() == "Test");
        REQUIRE(testMenu.items()[0]->id() == 0);
    }

    SECTION("Testing clickItem()") {
        testMenu.addItem("Test", callback);
        REQUIRE(mockGame.isRunning());
        testMenu.clickItem(0);
        REQUIRE(!mockGame.isRunning());
    }
}