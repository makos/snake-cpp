file(GLOB_RECURSE SOURCE *.cpp)

add_executable(snake ${SOURCE})

set_target_properties(snake PROPERTIES CXX_STANDARD 17)

target_include_directories(snake PUBLIC ${CMAKE_HOME_DIRECTORY}/include)

target_link_libraries(snake ncurses)
