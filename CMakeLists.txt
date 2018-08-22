cmake_minimum_required(VERSION 3.0.0)

project(snake)

file(GLOB_RECURSE SOURCE src/*.cpp)
file(GLOB_RECURSE TESTSRC tests/*.cpp)
include_directories(include)
target_include_directories(test PUBLIC tests)

add_executable(snake ${SOURCE})
add_executable(test ${TESTSRC})
link_libraries(ncurses)
# target_link_libraries(snake ncurses)

# target_include_directories(snake PUBLIC include/)

# install(TARGETS snake DESTINATION bin)