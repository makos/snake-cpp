#include "Renderer/Window.hpp"
#include "catch.hpp"
#include <typeinfo>

TEST_CASE("Window.hpp tests", "[window]") {
    // Following call doesn't refresh the screen, while initscr() does.
    newterm(NULL, stdout, stdin);
    Window testWin(5, 5, 0, 0);

    SECTION("General capabilities test") {
        // REQUIRE(typeid(testWin.get()) == typeid(WINDOW *));
        REQUIRE(testWin.clear() == OK);
        REQUIRE(testWin.erase() == OK);
        REQUIRE(testWin.refresh() == OK);
    }

    SECTION("Input test") {
        ungetch('a');
        REQUIRE(testWin.getKey() == 'a');
    }
}