#include "Util/Point.hpp"
#include "catch.hpp"

TEST_CASE("Point.hpp tests", "[point]") {
    Point testPoint(1, 3);
    Point otherPoint(2, 3);
    Point defaultPoint;
    Point copiedPoint(testPoint);

    REQUIRE(testPoint.x == 3);
    REQUIRE(testPoint.y == 1);
    REQUIRE(otherPoint.x == 3);
    REQUIRE(otherPoint.y == 2);

    SECTION("Testing comparison between different Points") {
        REQUIRE(testPoint != otherPoint);
    }

    SECTION("Testing addition") {
        Point cmp(3, 6);
        Point tmp = testPoint + otherPoint;
        REQUIRE(tmp == cmp);
    }

    SECTION("Testing addition in place") {
        Point cmp(3, 6);
        testPoint += otherPoint;
        REQUIRE(testPoint == cmp);
    }

    SECTION("Substraction") {
        Point cmp(1, 0);
        Point tmp = otherPoint - testPoint;
        REQUIRE(tmp == cmp);
    }

    SECTION("Substraction in place") {
        Point cmp(1, 0);
        otherPoint -= testPoint;
        REQUIRE(otherPoint == cmp);
    }

    SECTION("Testing default constructor") {
        REQUIRE(defaultPoint.y == 0);
        REQUIRE(defaultPoint.x == 0);
    }

    SECTION("Testing copy constructor") { REQUIRE(copiedPoint == testPoint); }

    SECTION("Testing public fields") {
        testPoint.x = 10;
        testPoint.y = 99;
        REQUIRE(testPoint.x == 10);
        REQUIRE(testPoint.y == 99);
    }
}