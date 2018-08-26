# Snake

A rewrite of my simple [C game in ncurses](https://github.com/makos/snake). Using a lot more fancier tech now.

[![Build Status](https://travis-ci.org/makos/snake-cpp.svg?branch=master)](https://travis-ci.org/makos/snake-cpp)

## About

This project started out as a simple rewrite to iteratively learn C++, but now I have bigger prospects. It may even progress to being an ncurses wrapper in C++. That will probably be moved to another repo, though.

## Building

Requirements:
* CMake version >3.0
* GCC version >5.0, Clang version >4.0 (those are tested, just make sure it supports C++17)
* ncurses library on your system (or [PDCurses](https://pdcurses.sourceforge.io/) on Windows)

## License

Licensed under GPL v3. See [LICENSE](LICENSE) for details.

[Catch2](https://github.com/catchorg/Catch2) library (catch.hpp) is licensed under Boost Software License. See the [file](tests/catch.hpp) for details.

&copy; Mateusz Makowski <matmakos@gmail.com>