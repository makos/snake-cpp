#include "Player/Player.hpp"
#include "Util/Point.hpp"
#include "catch.hpp"

TEST_CASE("Player.hpp tests", "[player]") {
    Player defaultPlayer;
    Player testPlayer(10, 20);

    Player pointPlayer(Point(30, 40));

    SECTION("default constructor") {
        SECTION("getPosition()") {
            REQUIRE(defaultPlayer.getPosition() == Point(0, 0));
        }

        SECTION("getChar()") { REQUIRE(defaultPlayer.getChar() == '#'); }
    }

    SECTION("setChar()") {
        defaultPlayer.setChar('@');
        REQUIRE(defaultPlayer.getChar() == '@');
    }

    SECTION("facing()") { REQUIRE(defaultPlayer.facing() == Point(1, 0)); }

    SECTION("face()") {
        defaultPlayer.face(Point(0, 1));
        REQUIRE(defaultPlayer.facing() == Point(0, 1));
    }

    SECTION("(y, x) constructor") {
        SECTION("getPosition()") {
            REQUIRE(testPlayer.getPosition() == Point(10, 20));
        }
    }

    SECTION("point constructor") {
        SECTION("getPosition()") {
            REQUIRE(pointPlayer.getPosition() == Point(30, 40));
        }
    }
}