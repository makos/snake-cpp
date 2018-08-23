#include "Player/Player.hpp"
#include "Player/Point.hpp"
#include "catch.hpp"

TEST_CASE("Player.hpp tests", "[player]") {
    Player defaultPlayer;
    Player testPlayer(10, 20);

    Point testPoint(30, 40);
    Player pointPlayer(testPoint);

    SECTION("Testing default constructor") {
        SECTION("Default constructor: getPosition()") {
            REQUIRE(defaultPlayer.getPosition().y == 0);
            REQUIRE(defaultPlayer.getPosition().x == 0);
        }

        SECTION("Default constructor: getChar()") {
            REQUIRE(defaultPlayer.getChar() == '#');
        }

        SECTION("Default constructor: setChar()") {
            defaultPlayer.setChar('@');
            REQUIRE(defaultPlayer.getChar() == '@');
        }

        SECTION("Default constructor: facing()") {
            Point temp(0, -1);
            REQUIRE(defaultPlayer.facing() == temp);
        }
    }

    SECTION("Testing (y, x) constructor") {
        Point tempPoint(10, 20);
        SECTION("(y, x) constructor: getPosition()") {
            REQUIRE(testPlayer.getPosition() == tempPoint);
        }

        SECTION("(y, x) constructor: getChar()") {
            REQUIRE(testPlayer.getChar() == '#');
        }

        SECTION("(y, x) constructor: facing()") {
            Point temp(0, -1);
            REQUIRE(testPlayer.facing() == temp);
        }
    }

    SECTION("Testing Point constructor") {
        SECTION("Point constructor: getPosition()") {
            REQUIRE(pointPlayer.getPosition().y == 30);
            REQUIRE(pointPlayer.getPosition().x == 40);
        }
    }
}