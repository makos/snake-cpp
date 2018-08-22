cmake_minimum_required(VERSION 3.0.0)

project(snake)

file(GLOB_RECURSE SOURCE src/*.cpp)
include_directories(include)

add_executable(snake ${SOURCE})
target_link_libraries(snake -l:pdcurses.a)

# target_include_directories(snake PUBLIC include/)

install(TARGETS snake DESTINATION bin)