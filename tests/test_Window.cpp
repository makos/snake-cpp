#include "Render/Window.hpp"
#include "catch.hpp"
#include <typeinfo>

TEST_CASE("Window.hpp tests", "[window]") {
    // Following call doesn't refresh the screen, while initscr() does.
    newterm(NULL, stdout, stdin);
    Window testWin(5, 5, 0, 0);

    SECTION("General capabilities test") {
        REQUIRE(typeid(testWin.get()) == typeid(WINDOW *));
        REQUIRE(testWin.setBox() == OK);
        REQUIRE(testWin.clearWin() == OK);
        REQUIRE(testWin.eraseWin() == OK);
        REQUIRE(testWin.refreshWin() == OK);
    }
}