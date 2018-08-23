file(GLOB_RECURSE SOURCE *.cpp)
# file(GLOB SOURCEMENU Menu/*.cpp)

add_executable(snake ${SOURCE})
target_include_directories(snake PUBLIC ${CMAKE_HOME_DIRECTORY}/include)
target_link_libraries(snake ncurses)
