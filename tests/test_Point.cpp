#include "Util/Point.hpp"
#include "catch.hpp"

TEST_CASE("Point.hpp tests", "[point]") {
    Point testPoint(1, 3);
    Point otherPoint(2, 3);
    Point defaultPoint;
    Point copiedPoint(testPoint);

    SECTION("comparison") { REQUIRE(testPoint != otherPoint); }

    SECTION("addition") {
        Point cmp(3, 6);
        Point tmp = testPoint + otherPoint;
        REQUIRE(tmp == cmp);
    }

    SECTION("addition inplace") {
        Point cmp(3, 6);
        testPoint += otherPoint;
        REQUIRE(testPoint == cmp);
    }

    SECTION("substraction") {
        Point cmp(1, 0);
        Point tmp = otherPoint - testPoint;
        REQUIRE(tmp == cmp);
    }

    SECTION("substraction inplace") {
        Point cmp(1, 0);
        otherPoint -= testPoint;
        REQUIRE(otherPoint == cmp);
    }

    SECTION("default constructor") { REQUIRE(defaultPoint == Point(0, 0)); }

    SECTION("copy constructor") { REQUIRE(copiedPoint == testPoint); }

    SECTION("public fields") {
        testPoint.x = 10;
        testPoint.y = 99;
        REQUIRE(testPoint == Point(99, 10));
    }
}