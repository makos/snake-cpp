#include "Renderer/Window.hpp"
#include "catch.hpp"
#include <typeinfo>

TEST_CASE("Window.hpp tests", "[window]") {
    // Following call doesn't refresh the screen, while initscr() does.
    newterm(NULL, stdout, stdin);
    Window testWin(5, 5, 0, 0);

    SECTION("get() return value") {
        REQUIRE(typeid(testWin.get()).name() == typeid(WINDOW *).name());
    }
    SECTION("clear()") { REQUIRE(testWin.clear() == OK); }
    SECTION("erase()") { REQUIRE(testWin.erase() == OK); }
    SECTION("refresh()") { REQUIRE(testWin.refresh() == OK); }

    SECTION("getKey()") {
        ungetch('a');
        REQUIRE(testWin.getKey() == 'a');
    }
}